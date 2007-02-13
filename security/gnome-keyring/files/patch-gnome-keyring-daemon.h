--- gnome-keyring-daemon.h.orig	Tue Feb 13 14:22:05 2007
+++ gnome-keyring-daemon.h	Tue Feb 13 14:22:20 2007
@@ -23,6 +23,7 @@
 #ifndef GNOME_KEYRING_DAEMON_H
 #define GNOME_KEYRING_DAEMON_H
 
+#include <sys/types.h>
 #include <time.h>
 #include <glib.h>
 
