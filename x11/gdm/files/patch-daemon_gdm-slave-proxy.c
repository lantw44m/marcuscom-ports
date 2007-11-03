--- daemon/gdm-slave-proxy.c.orig	2007-11-01 10:14:43.925210606 -0400
+++ daemon/gdm-slave-proxy.c	2007-11-01 10:14:57.116053855 -0400
@@ -28,6 +28,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <errno.h>
+#include <signal.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
