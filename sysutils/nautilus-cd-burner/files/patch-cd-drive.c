--- cd-drive.c.orig	Tue May 20 15:47:01 2003
+++ cd-drive.c	Tue May 20 17:55:56 2003
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
 
@@ -603,6 +609,69 @@
 }
 #endif /* __linux__ */
 
+#ifdef __FreeBSD__
+GList *
+freebsd_scan (gboolean recorder_only)
+{
+	const char *dev_type = "cd";
+	int fd;
+	int i = 0;
+	GList *cdroms_list = NULL;
+
+	while(1) {
+	    	gchar *dev = g_strdup_printf("/dev/%s%dc", dev_type, i);
+		int rspeed, wspeed;
+		CDDriveType type = CDDRIVE_TYPE_CD_RECORDER;
+		CDDrive *cdrom;
+		struct cam_device *cam_dev;
+
+		if (!g_file_test(dev, G_FILE_TEST_EXISTS)) {
+		    	g_free(dev);
+			return NULL;
+		}
+
+		if ((cam_dev = cam_open_spec_device(dev_type, i, O_RDWR, NULL)) == NULL) {
+		    	g_free(dev);
+			continue;
+		}
+
+		if ((fd = open(dev, O_RDWR, 0)) < 0) {
+		    	g_free(dev);
+			continue;
+		}
+
+		if (ioctl(fd, CDRIOCWRITESPEED, &wspeed) < 0) {
+		    	wspeed = 0;
+			type = CDDRIVE_TYPE_CD_DRIVE;
+		}
+
+		if (ioctl(fd, CDRIOCREADSPEED, &rspeed) < 0) {
+		    	rspeed = 0;
+		}
+
+		if (type == CDDRIVE_TYPE_CD_RECORDER || recorder_only) {
+		    	cdrom = g_new0 (CDDrive, 1);
+			cdrom->display_name = g_strdup_printf("%s %s %s", cam_dev->inq_data.vendor, cam_dev->inq_data.product, cam_dev->inq_data.revision);
+			cdrom->device = g_strdup(dev);
+			cdrom->max_speed_read = rspeed;
+			cdrom->max_speed_write = wspeed;
+			cdrom->cdrecord_id = g_strdup_printf ("%d,%d,%d", cam_dev->bus_id, cam_dev->target_id, cam_dev->target_lun);
+			cdrom->type = type;
+
+			cdroms_list = g_list_append (cdroms_list, cdrom);
+		}
+
+		g_free(dev);
+		free(cam_dev);
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
@@ -611,6 +680,10 @@
 
 #ifdef __linux__
 	cdroms = linux_scan (recorder_only);
+#endif
+
+#ifdef __FreeBSD__
+	cdroms = freebsd_scan (recorder_only);
 #endif
 
 	if (add_image) {
