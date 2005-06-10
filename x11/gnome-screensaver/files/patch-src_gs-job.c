--- src/gs-job.c.orig	Wed Jun  8 23:57:35 2005
+++ src/gs-job.c	Thu Jun  9 00:00:29 2005
@@ -29,7 +29,8 @@
 #include <sys/wait.h>
 #include <errno.h>
 
-#if defined(HAVE_SETPRIORITY) && defined(PRIO_PROCESS)
+#if defined(HAVE_SETPRIORITY)
+#include <sys/time.h>
 #include <sys/resource.h>
 #endif
 
