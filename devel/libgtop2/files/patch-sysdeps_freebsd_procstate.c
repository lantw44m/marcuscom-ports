--- sysdeps/freebsd/procstate.c.orig	Tue Aug 17 01:27:05 2004
+++ sysdeps/freebsd/procstate.c	Tue Aug 17 01:27:20 2004
@@ -28,7 +28,7 @@
 #include <glibtop_suid.h>
 
 #if !defined(__OpenBSD__)
-//&& (!defined __bsdi__)
+/*&& (!defined __bsdi__)*/
 #include <sys/user.h>
 #endif
 
