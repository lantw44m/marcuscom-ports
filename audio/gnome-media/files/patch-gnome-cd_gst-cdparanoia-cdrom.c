--- gnome-cd/gst-cdparanoia-cdrom.c.orig	Tue Aug 31 23:36:17 2004
+++ gnome-cd/gst-cdparanoia-cdrom.c	Tue Aug 31 23:36:19 2004
@@ -25,7 +25,16 @@
 
 #include <gconf/gconf-client.h>
 #include <gst/gst.h>
+#ifdef __linux__
 #include <linux/cdrom.h>
+#elif defined(__FreeBSD__)
+#include <sys/cdio.h>
+#include <sys/cdrio.h>
+#define CD_FRAMES		75
+#define CD_MSF_OFFSET		150
+#define CDROM_DATA_TRACK	0x04
+#define CDROM_LEADOUT		0xAA
+#endif
 
 static GnomeCDRomClass *parent_class = NULL;
 
@@ -40,7 +49,11 @@
 struct _GstCdparanoiaCDRomPrivate {
 	GnomeCDRomUpdate update;
 
+#ifdef __FreeBSD__
+	struct ioc_toc_header *tochdr;
+#else
 	struct cdrom_tochdr *tochdr;
+#endif
 	int number_tracks;
 	unsigned char track0, track1;
 	char *cd_device;
@@ -89,6 +102,23 @@
 
 static GnomeCDRomMSF blank_msf = { 0, 0, 0 };
 
+#ifdef __FreeBSD__
+static guint64
+msf_struct_to_frames (struct ioc_play_msf *msf, int entry)
+{
+	guint64 frames;
+	if (entry == 0) {
+		frames =
+		    (msf->start_m * 60 * CD_FRAMES) +
+		    (msf->start_s * CD_FRAMES) + msf->start_f;
+	} else {
+		frames =
+		    (msf->end_m * 60 * CD_FRAMES) +
+		    (msf->end_s * CD_FRAMES) + msf->end_f;
+	}
+	return (frames - CD_MSF_OFFSET);
+}
+#else
 static guint64
 msf_struct_to_frames (struct cdrom_msf *msf, int entry)
 {
@@ -104,6 +134,7 @@
 	}
 	return (frames - CD_MSF_OFFSET);
 }
+#endif
 
 static int
 msf_to_frames (GnomeCDRomMSF * msf)
@@ -124,6 +155,19 @@
 	msf->frame = frames;
 }
 
+#ifdef __FreeBSD__
+static void
+frames_to_msf_struct (union msf_lba *msflba, int frames)
+{
+	/* Now convert the difference in frame lengths back into MSF
+	   format */
+	msflba->msf.minute = frames / (60 * CD_FRAMES);
+	frames -= (msflba->msf.minute * 60 * CD_FRAMES);
+	msflba->msf.second = frames / CD_FRAMES;
+	frames -= (msflba->msf.second * CD_FRAMES);
+	msflba->msf.frame = frames;
+}
+#else
 static void
 frames_to_msf_struct (struct cdrom_msf0 *msf, int frames)
 {
@@ -135,6 +179,7 @@
 	frames -= (msf->second * CD_FRAMES);
 	msf->frame = frames;
 }
+#endif
 
 static void
 add_msf (GnomeCDRomMSF * msf1, GnomeCDRomMSF * msf2, GnomeCDRomMSF * dest)
@@ -311,7 +356,11 @@
 {
 	GstCdparanoiaCDRom *lcd = GST_CDPARANOIA_CDROM (cdrom);
 	GstCdparanoiaCDRomPrivate *priv;
+#ifdef __FreeBSD__
+	struct ioc_read_toc_single_entry tocentry;
+#else
 	struct cdrom_tocentry tocentry;
+#endif
 	int i, j;
 	GError *error;
 
@@ -322,15 +371,24 @@
 		return;
 	}
 
+#ifdef __FreeBSD__
+	if (ioctl (cdrom->fd, CDIOREADTOCHEADER, priv->tochdr) < 0) {
+#else
 	if (ioctl (cdrom->fd, CDROMREADTOCHDR, priv->tochdr) < 0) {
+#endif
 		g_warning ("Error reading CD header");
 		gst_cdparanoia_cdrom_close (lcd);
 
 		return;
 	}
 
+#ifdef __FreeBSD__
+	priv->track0 = priv->tochdr->starting_track;
+	priv->track1 = priv->tochdr->ending_track;
+#else
 	priv->track0 = priv->tochdr->cdth_trk0;
 	priv->track1 = priv->tochdr->cdth_trk1;
+#endif
 	priv->number_tracks = priv->track1 - priv->track0 + 1;
 
 	gst_cdparanoia_cdrom_invalidate (lcd);
@@ -338,6 +396,21 @@
 	    g_malloc ((priv->number_tracks +
 		       1) * sizeof (GstCdparanoiaCDRomTrackInfo));
 	for (i = 0, j = priv->track0; i < priv->number_tracks; i++, j++) {
+#ifdef __FreeBSD__
+		tocentry.track = j;
+		tocentry.address_format = CD_MSF_FORMAT;
+
+		if (ioctl (cdrom->fd, CDIOREADTOCENTRY, &tocentry) < 0) {
+			g_warning ("IOCtl failed");
+			continue;
+		}
+
+		priv->track_info[i].track = j;
+		priv->track_info[i].audio_track =
+		    tocentry.entry.control != CDROM_DATA_TRACK ? 1 : 0;
+		ASSIGN_MSF (priv->track_info[i].address,
+			    tocentry.entry.addr.msf);
+#else
 		tocentry.cdte_track = j;
 		tocentry.cdte_format = CDROM_MSF;
 
@@ -351,7 +424,19 @@
 		    tocentry.cdte_ctrl != CDROM_DATA_TRACK ? 1 : 0;
 		ASSIGN_MSF (priv->track_info[i].address,
 			    tocentry.cdte_addr.msf);
+#endif
 	}
+#ifdef __FreeBSD__
+	tocentry.track = CDROM_LEADOUT;
+	tocentry.address_format = CD_MSF_FORMAT;
+	if (ioctl (cdrom->fd, CDIOREADTOCENTRY, &tocentry) < 0) {
+		g_warning ("Error getting leadout");
+		gst_cdparanoia_cdrom_invalidate (lcd);
+		return;
+	}
+	ASSIGN_MSF (priv->track_info[priv->number_tracks].address,
+		    tocentry.entry.addr.msf);
+#else
 
 	tocentry.cdte_track = CDROM_LEADOUT;
 	tocentry.cdte_format = CDROM_MSF;
@@ -362,6 +447,7 @@
 	}
 	ASSIGN_MSF (priv->track_info[priv->number_tracks].address,
 		    tocentry.cdte_addr.msf);
+#endif
 	calculate_track_lengths (lcd);
 
 	gst_cdparanoia_cdrom_close (lcd);
@@ -387,7 +473,11 @@
 	}
 
 	if (status->cd != GNOME_CDROM_STATUS_TRAY_OPEN) {
+#ifdef __FreeBSD__
+		if (ioctl (cdrom->fd, CDIOCEJECT, 0) < 0) {
+#else
 		if (ioctl (cdrom->fd, CDROMEJECT, 0) < 0) {
+#endif
 			if (error) {
 				*error = g_error_new (GNOME_CDROM_ERROR,
 						      GNOME_CDROM_ERROR_SYSTEM_ERROR,
@@ -555,7 +645,11 @@
 	GstCdparanoiaCDRom *lcd;
 	GstCdparanoiaCDRomPrivate *priv;
 	GnomeCDRomStatus *status;
+#ifdef __FreeBSD__
+	struct ioc_play_msf msf;
+#else
 	struct cdrom_msf msf;
+#endif
 	gboolean ret;
 	guint64 frames;
 
@@ -630,9 +724,15 @@
 	default:
 		/* Start playing */
 		if (start == NULL) {
+#ifdef __FreeBSD__
+			msf.start_m = status->absolute.minute;
+			msf.start_s = status->absolute.second;
+			msf.start_f =  status->absolute.frame;
+#else
 			msf.cdmsf_min0 = status->absolute.minute;
 			msf.cdmsf_sec0 = status->absolute.second;
 			msf.cdmsf_frame0 = status->absolute.frame;
+#endif
 		} else {
 			if (start_track > 0 &&
 			    priv && priv->track_info &&
@@ -642,19 +742,43 @@
 					 track_info[start_track -
 						    1].address, start,
 					 &tmpmsf);
+#ifdef __FreeBSD__
+
+				msf.start_m = tmpmsf.minute;
+				msf.start_s = tmpmsf.second;
+				msf.start_f = tmpmsf.frame;
+#else
 				msf.cdmsf_min0 = tmpmsf.minute;
 				msf.cdmsf_sec0 = tmpmsf.second;
 				msf.cdmsf_frame0 = tmpmsf.frame;
+#endif
 			} else {
+#ifdef __FreeBSD__
+				msf.start_m = start->minute;
+				msf.start_s = start->second;
+				msf.start_f = start->frame;
+#else
 				msf.cdmsf_min0 = start->minute;
 				msf.cdmsf_sec0 = start->second;
 				msf.cdmsf_frame0 = start->frame;
+#endif
 			}
 		}
 
 		if (finish == NULL) {
 			if (priv && priv->track_info &&
 			    priv->number_tracks > 0) {
+#ifdef __FreeBSD__
+				msf.end_m =
+				    priv->track_info[priv->number_tracks].
+				    address.minute;
+				msf.end_s =
+				    priv->track_info[priv->number_tracks].
+				    address.second;
+				msf.end_f =
+				    priv->track_info[priv->number_tracks].
+				    address.frame;
+#else
 				msf.cdmsf_min1 =
 				    priv->track_info[priv->number_tracks].
 				    address.minute;
@@ -664,10 +788,17 @@
 				msf.cdmsf_frame1 =
 				    priv->track_info[priv->number_tracks].
 				    address.frame;
+#endif
 			} else {
+#ifdef __FreeBSD__
+				msf.end_m = 0;
+				msf.end_s = 0;
+				msf.end_f = 0;
+#else
 				msf.cdmsf_min1 = 0;
 				msf.cdmsf_sec1 = 0;
 				msf.cdmsf_frame1 = 0;
+#endif
 			}
 		} else {
 			if (finish_track > 0 &&
@@ -679,13 +810,25 @@
 					 track_info[finish_track -
 						    1].address, finish,
 					 &tmpmsf);
+#ifdef __FreeBSD__
+				msf.end_m = tmpmsf.minute;
+				msf.end_s = tmpmsf.second;
+				msf.end_f = tmpmsf.frame;
+#else
 				msf.cdmsf_min1 = tmpmsf.minute;
 				msf.cdmsf_sec1 = tmpmsf.second;
 				msf.cdmsf_frame1 = tmpmsf.frame;
+#endif
 			} else {
+#ifdef __FreeBSD__
+				msf.end_m = finish->minute;
+				msf.end_s = finish->second;
+				msf.end_f = finish->frame;
+#else
 				msf.cdmsf_min1 = finish->minute;
 				msf.cdmsf_sec1 = finish->second;
 				msf.cdmsf_frame1 = finish->frame;
+#endif
 			}
 		}
 
@@ -944,7 +1087,11 @@
 	GstCdparanoiaCDRom *lcd;
 	GstCdparanoiaCDRomPrivate *priv;
 	GnomeCDRomStatus *realstatus;
+#ifdef __FreeBSD__
+	struct cd_sub_channel_position_data subchnl;
+#else
 	struct cdrom_subchnl subchnl;
+#endif
 	int cur_gst_status;
 	int cd_status;
 	guint64 value = 0;
@@ -966,6 +1113,7 @@
 		return FALSE;
 	}
 
+#ifndef __FreeBSD__
 	cd_status = ioctl (cdrom->fd, CDROM_DRIVE_STATUS, CDSL_CURRENT);
 	if (cd_status != -1) {
 		switch (cd_status) {
@@ -1019,6 +1167,7 @@
 		*status = NULL;
 		return FALSE;
 	}
+#endif
 
 	/* Get the volume */
 	/* TODO: get the mixer volume */
@@ -1058,21 +1207,37 @@
 		    msf_to_frames (&priv->track_info[priv->cur_track - 1].
 				   address) + CD_MSF_OFFSET;
 	}
+#ifdef __FreeBSD__
+	subchnl.track_number = priv->cur_track;
+	frames_to_msf_struct (&subchnl.reladdr,
+			      priv->cur_rel_frame);
+	frames_to_msf_struct (&subchnl.absaddr,
+			      priv->cur_abs_frame);
+#else
 	subchnl.cdsc_trk = priv->cur_track;
 	frames_to_msf_struct (&subchnl.cdsc_reladdr.msf,
 			      priv->cur_rel_frame);
 	frames_to_msf_struct (&subchnl.cdsc_absaddr.msf,
 			      priv->cur_abs_frame);
+#endif
 
 	realstatus->track = 1;
 	switch (cur_gst_status) {
 	case GST_STATE_PLAYING:
 		realstatus->audio = GNOME_CDROM_AUDIO_PLAY;
+#ifdef __FreeBSD__
+		ASSIGN_MSF (realstatus->relative,
+			    subchnl.reladdr.msf);
+		ASSIGN_MSF (realstatus->absolute,
+			    subchnl.absaddr.msf);
+		realstatus->track = subchnl.track_number;
+#else
 		ASSIGN_MSF (realstatus->relative,
 			    subchnl.cdsc_reladdr.msf);
 		ASSIGN_MSF (realstatus->absolute,
 			    subchnl.cdsc_absaddr.msf);
 		realstatus->track = subchnl.cdsc_trk;
+#endif
 		if (priv && realstatus->track > 0 &&
 		    realstatus->track <= priv->number_tracks) {
 			/* track_info may not be initialized */
@@ -1084,11 +1249,19 @@
 
 	case GST_STATE_PAUSED:
 		realstatus->audio = GNOME_CDROM_AUDIO_PAUSE;
+#ifdef __FreeBSD__
+		ASSIGN_MSF (realstatus->relative,
+			    subchnl.reladdr.msf);
+		ASSIGN_MSF (realstatus->absolute,
+			    subchnl.absaddr.msf);
+		realstatus->track = subchnl.track_number;
+#else
 		ASSIGN_MSF (realstatus->relative,
 			    subchnl.cdsc_reladdr.msf);
 		ASSIGN_MSF (realstatus->absolute,
 			    subchnl.cdsc_absaddr.msf);
 		realstatus->track = subchnl.cdsc_trk;
+#endif
 		if (priv && realstatus->track > 0 &&
 		    realstatus->track <= priv->number_tracks) {
 			/* track_info may not be initialized */
@@ -1101,11 +1274,20 @@
 	case GST_STATE_NULL:
 	case GST_STATE_READY:
 		realstatus->audio = GNOME_CDROM_AUDIO_COMPLETE;
+#ifdef __FreeBSD__
+		ASSIGN_MSF (realstatus->relative,
+			    subchnl.reladdr.msf);
+
+		ASSIGN_MSF (realstatus->absolute,
+			    subchnl.absaddr.msf);
+		realstatus->track = subchnl.track_number;
+#else
 		ASSIGN_MSF (realstatus->relative,
 			    subchnl.cdsc_reladdr.msf);
 		ASSIGN_MSF (realstatus->absolute,
 			    subchnl.cdsc_absaddr.msf);
 		realstatus->track = subchnl.cdsc_trk;
+#endif
 		if (priv && realstatus->track > 0 &&
 		    realstatus->track <= priv->number_tracks) {
 			/* track_info may not be initialized */
@@ -1133,7 +1315,11 @@
 		return FALSE;
 	}
 
+#ifdef __FreeBSD__
+	if (ioctl (cdrom->fd, CDIOCCLOSE) < 0) {
+#else
 	if (ioctl (cdrom->fd, CDROMCLOSETRAY) < 0) {
+#endif
 		if (error) {
 			*error = g_error_new (GNOME_CDROM_ERROR,
 					      GNOME_CDROM_ERROR_SYSTEM_ERROR,
@@ -1155,7 +1341,11 @@
 {
 	GstCdparanoiaCDRom *lcd;
 	GstCdparanoiaCDRomPrivate *priv;
+#ifdef __FreeBSD__
+	struct ioc_vol vol;
+#else
 	struct cdrom_volctrl vol;
+#endif
 
 	lcd = GST_CDPARANOIA_CDROM (cdrom);
 	priv = lcd->priv;
@@ -1164,10 +1354,19 @@
 		return FALSE;
 	}
 
+#ifdef __FreeBSD__
+	vol.vol[0] = volume;
+	vol.vol[1] = vol.vol[2] = vol.vol[3] = volume;
+#else
 	vol.channel0 = volume;
 	vol.channel1 = vol.channel2 = vol.channel3 = volume;
+#endif
 
+#ifdef __FreeBSD__
+	if (ioctl (cdrom->fd, CDIOCSETVOL, &vol) < 0) {
+#else
 	if (ioctl (cdrom->fd, CDROMVOLCTRL, &vol) < 0) {
+#endif
 		if (error) {
 			*error = g_error_new (GNOME_CDROM_ERROR,
 					      GNOME_CDROM_ERROR_SYSTEM_ERROR,
@@ -1204,7 +1403,11 @@
 	}
 
 	/* Fire a harmless ioctl at the device. */
+#ifdef __FreeBSD__
+	if (ioctl (fd, CDIOCCAPABILITY, 0) < 0) {
+#else
 	if (ioctl (fd, CDROM_GET_CAPABILITY, 0) < 0) {
+#endif
 		/* Failed, it's not a CDROM drive */
 		close (fd);
 
@@ -1302,7 +1505,11 @@
 gst_cdparanoia_cdrom_init (GstCdparanoiaCDRom * cdrom)
 {
 	cdrom->priv = g_new0 (GstCdparanoiaCDRomPrivate, 1);
+#ifdef __FreeBSD__
+	cdrom->priv->tochdr = g_new0 (struct ioc_toc_header, 1);
+#else
 	cdrom->priv->tochdr = g_new0 (struct cdrom_tochdr, 1);
+#endif
 	cdrom->priv->track_info = NULL;
 	cdrom->priv->cd_device = NULL;
 	cdrom->priv->cur_track = 1;
