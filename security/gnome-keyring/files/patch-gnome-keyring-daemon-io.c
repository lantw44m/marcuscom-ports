--- gnome-keyring-daemon-io.c.orig	Mon Dec  8 15:39:44 2003
+++ gnome-keyring-daemon-io.c	Mon Dec  8 15:40:28 2003
@@ -30,6 +30,8 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <sys/uio.h>
+#include <unistd.h>
 
 #include "gnome-keyring.h"
 #include "gnome-keyring-private.h"
