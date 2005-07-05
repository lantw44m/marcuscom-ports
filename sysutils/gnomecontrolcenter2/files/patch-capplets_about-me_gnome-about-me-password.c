--- capplets/about-me/gnome-about-me-password.c.orig	Tue Jul  5 14:14:11 2005
+++ capplets/about-me/gnome-about-me-password.c	Tue Jul  5 14:14:50 2005
@@ -35,7 +35,12 @@
 #include <sys/wait.h>
 #include <sys/poll.h>
 #include <termios.h>
+#ifndef __FreeBSD__
 #include <pty.h>
+#else
+#include <sys/types.h>
+#include <libutil.h>
+#endif
 
 #include "capplet-util.h"
 #include "eel-alert-dialog.h"
