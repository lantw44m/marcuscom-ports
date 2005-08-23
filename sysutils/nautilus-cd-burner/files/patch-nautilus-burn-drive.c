--- nautilus-burn-drive.c.orig	Mon Aug 22 18:58:32 2005
+++ nautilus-burn-drive.c	Mon Aug 22 20:20:06 2005
@@ -471,7 +471,6 @@ get_disc_type (const char *dev_path)
 	struct cd_toc_entry              entry;
 	int                              i;
 #endif
-	int                              type;
 #ifndef CDROM_DATA_TRACK
 #define CDROM_DATA_TRACK 4
 #endif
@@ -481,7 +480,7 @@ get_disc_type (const char *dev_path)
 	    	return -1;
 	}
 
-	if (ioctl (fd, CDIOREADTOCHEADER, &header) == 0) {
+	if (ioctl (fd, CDIOREADTOCHEADER, &header) != 0) {
 		close (fd);
 	    	return -1;
 	}
