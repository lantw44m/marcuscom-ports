--- daemon/gdm-greeter-session.c.orig	2007-11-01 09:53:22.605462146 -0400
+++ daemon/gdm-greeter-session.c	2007-11-01 09:53:41.764236795 -0400
@@ -31,6 +31,7 @@
 #include <ctype.h>
 #include <pwd.h>
 #include <grp.h>
+#include <signal.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
