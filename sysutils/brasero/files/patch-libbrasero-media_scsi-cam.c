--- libbrasero-media/scsi-cam.c.orig	2009-10-08 22:34:11.000000000 -0400
+++ libbrasero-media/scsi-cam.c	2009-10-08 22:35:09.000000000 -0400
@@ -193,6 +193,9 @@ brasero_device_handle_open (const gchar 
 				*code = BRASERO_SCSI_ERRNO;
 		}
 
+		if (fd > -1)
+			close (fd);
+
 		return NULL;
 	}
 
