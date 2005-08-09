--- nautilus-burn-drive.c.orig	Thu Aug  4 16:23:24 2005
+++ nautilus-burn-drive.c	Tue Aug  9 19:42:32 2005
@@ -48,6 +48,13 @@
 #include <sys/cdio.h>
 #include <sys/cdrio.h>
 #include <camlib.h>
+#define CDS_AUDIO   100
+#define CDS_DATA_1  101
+#define CDS_DATA_2  102
+#define CDS_MIXED   105
+#define CDS_NO_INFO 0
+#define CDS_XA_2_1  103
+#define CDS_XA_2_2  104
 #endif /* __FreeBSD__ */
 
 #ifdef HAVE_SYS_CDIO_H
@@ -484,7 +491,7 @@ get_disc_type (const char *dev_path)
 		entry.track++) {
 	    	entry.address_format = CD_LBA_FORMAT;
 		if (ioctl (fd, CDIOREADTOCENTRY, &entry) == 0) {
-		    	if (entry.entry.control & CDROM_DATA_TRACK) {
+		    	if (!(entry.entry.control & CDROM_DATA_TRACK)) {
 			    	type = CDS_AUDIO;
 				break;
 			}
