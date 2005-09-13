--- src/gs-job.c.orig	Wed Sep  7 09:23:59 2005
+++ src/gs-job.c	Mon Sep 12 13:24:11 2005
@@ -29,7 +29,8 @@
 #include <sys/wait.h>
 #include <errno.h>
 
-#if defined(HAVE_SETPRIORITY) && defined(PRIO_PROCESS)
+#if defined(HAVE_SETPRIORITY)
+#include <sys/time.h>
 #include <sys/resource.h>
 #endif
 
@@ -655,9 +659,11 @@ gs_job_set_widget  (GSJob     *job,
 static const char *known_locations [] = {
         SAVERDIR,
         LIBEXECDIR "/xscreensaver",
-        "/usr/X11R6/lib/xscreensaver",
+        "%%X11BASE%%/lib/xscreensaver",
         "/usr/libexec/xscreensaver",
         "/usr/lib/xscreensaver",
+        "%%X11BASE%%/bin/xscreensaver-hacks",
+        "%%X11BASE%%/bin",
         NULL
 };
 
