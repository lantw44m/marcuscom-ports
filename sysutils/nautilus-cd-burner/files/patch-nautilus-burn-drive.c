--- nautilus-burn-drive.c.orig	Thu Jun  9 14:32:26 2005
+++ nautilus-burn-drive.c	Thu Jun  9 14:36:28 2005
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
