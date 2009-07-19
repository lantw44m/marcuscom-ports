--- libbrasero-media/brasero-drive.c.orig	2009-07-13 21:34:34.000000000 -0400
+++ libbrasero-media/brasero-drive.c	2009-07-19 00:59:26.000000000 -0400
@@ -35,6 +35,13 @@
 #include <unistd.h>
 #include <string.h>
 
+#ifdef HAVE_CAM_LIB_H
+#include <errno.h>
+#include <stdio.h>
+#include <fcntl.h>
+#include <camlib.h>
+#endif
+
 #include <glib.h>
 #include <glib-object.h>
 #include <glib/gi18n-lib.h>
@@ -228,10 +235,31 @@ brasero_drive_eject (BraseroDrive *drive
 gchar *
 brasero_drive_get_bus_target_lun_string (BraseroDrive *drive)
 {
+#ifdef HAVE_CAM_LIB_H
+	struct cam_device *cam_dev;
+	char *addr;
+#endif
+
 	g_return_val_if_fail (drive != NULL, NULL);
 	g_return_val_if_fail (BRASERO_IS_DRIVE (drive), NULL);
 
+#ifdef HAVE_CAM_LIB_H
+	cam_dev = cam_open_device (brasero_drive_get_device (drive), O_RDWR);
+
+	if (cam_dev == NULL) {
+		BRASERO_MEDIA_LOG ("CAM: Failed to open %s: %s", brasero_drive_get_device (drive), g_strerror (errno));
+		return NULL;
+	}
+
+	addr = g_strdup_printf ("%i,%i,%i", cam_dev->path_id, cam_dev->target_id, cam_dev->target_lun);
+
+	cam_close_device (cam_dev);
+
+	return addr;
+#else
+
 	return NULL;
+#endif
 }
 
 /**
