--- cd-drive.c.orig	Mon May 19 06:16:13 2003
+++ cd-drive.c	Wed May 21 02:56:21 2003
@@ -40,6 +40,12 @@
 #include <scsi/sg.h>
 #endif /* __linux__ */
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#include <sys/cdrio.h>
+#include <camlib.h>
+#endif
+
 #include <glib.h>
 #include <libgnome/gnome-i18n.h>
 
@@ -603,6 +609,72 @@
 }
 #endif /* __linux__ */
 
+#ifdef __FreeBSD__
+static GList *
+freebsd_scan (gboolean recorder_only)
+{
+	GList *cdroms_list = NULL;
+	const char *dev_type = "cd";
+	int fd;
+	int i = 0;
+
+	while (1) {
+		CDDriveType type = CDDRIVE_TYPE_CD_RECORDER;
+		CDDrive *cdrom;
+		struct cam_device *cam_dev;
+	    	gchar *dev = g_strdup_printf ("/dev/%s%dc", dev_type, i);
+		int rspeed, wspeed;
+
+		if (!g_file_test (dev, G_FILE_TEST_EXISTS)) {
+		    	g_free (dev);
+			break;
+		}
+
+		if ((cam_dev = cam_open_spec_device (dev_type, i, O_RDWR, NULL)) == NULL) {
+		    	g_free (dev);
+			i++;
+			continue;
+		}
+
+		if ((fd = open (dev, O_RDWR, 0)) < 0) {
+		    	g_free (dev);
+			free (cam_dev);
+			i++;
+			continue;
+		}
+
+		if (ioctl (fd, CDRIOCWRITESPEED, &wspeed) < 0) {
+		    	wspeed = 0;
+			type = CDDRIVE_TYPE_CD_DRIVE;
+		}
+
+		if (ioctl (fd, CDRIOCREADSPEED, &rspeed) < 0) {
+		    	rspeed = 0;
+		}
+
+		if (type == CDDRIVE_TYPE_CD_RECORDER || recorder_only == FALSE) {
+		    	cdrom = g_new0 (CDDrive, 1);
+			cdrom->display_name = g_strdup_printf ("%s %s %s", cam_dev->inq_data.vendor, cam_dev->inq_data.product, cam_dev->inq_data.revision);
+			cdrom->device = g_strdup (dev);
+			cdrom->max_speed_read = rspeed;
+			cdrom->max_speed_write = wspeed;
+			cdrom->cdrecord_id = g_strdup_printf ("%d,%d,%d", cam_dev->bus_id, cam_dev->target_id, cam_dev->target_lun);
+			cdrom->type = type;
+
+			cdroms_list = g_list_append (cdroms_list, cdrom);
+		}
+
+		g_free (dev);
+		free (cam_dev);
+
+		i++;
+	}
+
+	return cdroms_list;
+}
+#endif /* __FreeBSD__ */
+	
+
 GList *
 scan_for_cdroms (gboolean recorder_only, gboolean add_image)
 {
@@ -611,6 +683,10 @@
 
 #ifdef __linux__
 	cdroms = linux_scan (recorder_only);
+#endif
+
+#ifdef __FreeBSD__
+	cdroms = freebsd_scan (recorder_only);
 #endif
 
 	if (add_image) {
