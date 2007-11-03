--- daemon/gdm-session-worker-job.c.orig	2007-11-01 10:00:45.085195185 -0400
+++ daemon/gdm-session-worker-job.c	2007-11-01 10:01:33.067624236 -0400
@@ -31,6 +31,7 @@
 #include <ctype.h>
 #include <pwd.h>
 #include <grp.h>
+#include <signal.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
