--- sysdeps/freebsd/fsusage.c.orig	2007-11-03 00:00:42.000000000 -0400
+++ sysdeps/freebsd/fsusage.c	2007-11-03 00:03:44.000000000 -0400
@@ -22,14 +22,7 @@
 #include <stdlib.h>
 
 void
-_glibtop_freebsd_get_fsusage_read_write(glibtop *server,
-                                        glibtop_fsusage *buf,
-                                        const char *path);
-
-void
-_glibtop_freebsd_get_fsusage_read_write(glibtop *server,
-                                        glibtop_fsusage *buf,
-                                        const char *path)
+glibtop_get_fsusage_s(glibtop *server, glibtop_fsusage *buf, const char *path)
 {
         int result;
         struct statfs sfs;
