--- sys/cdrom/gstcdplayer_ioctl_bsd.h.orig	Mon Dec  8 21:01:50 2003
+++ sys/cdrom/gstcdplayer_ioctl_bsd.h	Mon Dec  8 23:13:54 2003
@@ -139,6 +139,7 @@
 {
 	struct ioc_toc_header toc_header;
 	struct ioc_read_toc_entry toc_entry;
+	struct cd_toc_entry toc_entry_data;
 	guint i;
 
 	cd->fd = open(device,O_RDONLY | O_NONBLOCK);
@@ -148,7 +149,7 @@
 	}
 
 	/* get the toc header information */
-	if (ioctl(cd->fd,CDIOREADTOCHDR,&toc_header) != 0) {
+	if (ioctl(cd->fd,CDIOREADTOCHEADER,&toc_header) != 0) {
 		close(cd->fd);
 		cd->fd = -1;
 		return FALSE;
@@ -158,6 +159,8 @@
 	for (i = 1; i <= toc_header.ending_track; i++) {
 		toc_entry.address_format = CD_MSF_FORMAT;
 		toc_entry.starting_track = i;
+		toc_entry.data = &toc_entry_data;
+		toc_entry.data_len = sizeof(toc_entry_data);
 
 		if (ioctl(cd->fd,CDIOREADTOCENTRYS,&toc_entry) != 0) {
 			close(cd->fd);
@@ -165,9 +168,9 @@
 			return FALSE;
 		}
 
-		cd->tracks[i].minute = toc_entry.entry.addr.msf.minute;
-		cd->tracks[i].second = toc_entry.entry.addr.msf.second;
-		cd->tracks[i].frame = toc_entry.entry.addr.msf.frame;
+		cd->tracks[i].minute = toc_entry.data->addr.msf.minute;
+		cd->tracks[i].second = toc_entry.data->addr.msf.second;
+		cd->tracks[i].frame = toc_entry.data->addr.msf.frame;
 		cd->tracks[i].data_track = (toc_entry.data->control & 4) == 4;
 	}
 
@@ -183,9 +186,9 @@
 		return FALSE;
 	}
 
-	cd->tracks[LEADOUT].minute = toc_entry.entry.addr.msf.minute;
-	cd->tracks[LEADOUT].second = toc_entry.entry.addr.msf.second;
-	cd->tracks[LEADOUT].frame = toc_entry.entry.addr.msf.frame;
+	cd->tracks[LEADOUT].minute = toc_entry.data->addr.msf.minute;
+	cd->tracks[LEADOUT].second = toc_entry.data->addr.msf.second;
+	cd->tracks[LEADOUT].frame = toc_entry.data->addr.msf.frame;
 
 	cd->num_tracks = toc_header.ending_track;
 
@@ -221,6 +224,8 @@
 		return FALSE;
 	}
 
+	/* lets return TRUE and lets see what happes (may not be correct)*/
+	return TRUE;
 }
 
 gboolean cd_pause(struct cd *cd)
@@ -318,7 +323,7 @@
 		return -1;
 	}
 
-	return sub_channel.data->track_number;
+	return sub_channel.data->what.track_info.track_number;
 }
 
 gboolean cd_close(struct cd *cd)
