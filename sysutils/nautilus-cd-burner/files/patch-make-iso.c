--- make-iso.c.orig	Sun Apr 13 03:24:31 2003
+++ make-iso.c	Sun Apr 13 03:25:19 2003
@@ -21,7 +21,12 @@
   
    Authors: Alexander Larsson <alexl@redhat.com>
 */
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
