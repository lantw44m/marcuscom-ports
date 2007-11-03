--- daemon/gdm-server.c.orig	2007-11-01 09:55:49.964708363 -0400
+++ daemon/gdm-server.c	2007-11-01 09:56:08.940482938 -0400
@@ -32,6 +32,7 @@
 #include <pwd.h>
 #include <grp.h>
 #include <signal.h>
+#include <sys/resource.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
