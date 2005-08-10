--- nautilus-burn-drive.c.orig	Thu Aug  4 16:23:24 2005
+++ nautilus-burn-drive.c	Tue Aug  9 22:56:36 2005
@@ -48,6 +48,14 @@
 #include <sys/cdio.h>
 #include <sys/cdrio.h>
 #include <camlib.h>
+#define CDS_DISC_OK 0
+#define CDS_AUDIO   100
+#define CDS_DATA_1  101
+#define CDS_DATA_2  102
+#define CDS_MIXED   105
+#define CDS_NO_INFO -1
+#define CDS_XA_2_1  103
+#define CDS_XA_2_2  104
 #endif /* __FreeBSD__ */
 
 #ifdef HAVE_SYS_CDIO_H
@@ -470,11 +478,12 @@ get_disc_type (const char *dev_path)
 
 	fd = open (dev_path, O_RDONLY|O_NONBLOCK);
 	if (fd < 0) {
-	    	return -1;
+	    	return CDS_NO_INFO;
 	}
 
-	if (ioctl (fd, CDIOREADTOCHEADER, &header) == 0) {
-	    	return -1;
+	if (ioctl (fd, CDIOREADTOCHEADER, &header) != CDS_DISC_OK) {
+		close (fd);
+	    	return CDS_NO_INFO;
 	}
 
 	type = CDS_DATA_1;
@@ -484,7 +493,7 @@ get_disc_type (const char *dev_path)
 		entry.track++) {
 	    	entry.address_format = CD_LBA_FORMAT;
 		if (ioctl (fd, CDIOREADTOCENTRY, &entry) == 0) {
-		    	if (entry.entry.control & CDROM_DATA_TRACK) {
+		    	if (!(entry.entry.control & CDROM_DATA_TRACK)) {
 			    	type = CDS_AUDIO;
 				break;
 			}
@@ -506,6 +515,7 @@ get_disc_type (const char *dev_path)
 	}
 
 #endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)*/
+	close (fd);
 	return type;
 #elif defined(__linux__)
 	fd = open (dev_path, O_RDONLY|O_NONBLOCK);
@@ -627,8 +637,6 @@ nautilus_burn_drive_get_media_type_from_
 
 			return NAUTILUS_BURN_MEDIA_TYPE_UNKNOWN;
 		}
-	} else {
-		g_warning ("Could not read MMC profile of %s", device);
 	}
 
 	close_ioctl_handle (ioctl_handle);
