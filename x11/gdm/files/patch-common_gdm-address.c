--- common/gdm-address.c.orig	2008-01-31 03:07:58.000000000 -0500
+++ common/gdm-address.c	2008-01-31 03:11:17.000000000 -0500
@@ -26,12 +26,13 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>
+#include <sys/types.h>
+#include <sys/param.h>
 #ifdef HAS_SYS_SOCKET
 #include <sys/socket.h>
 #endif
 #include <netdb.h>
 #include <sys/ioctl.h>
-#include <net/if.h>
 
 #ifndef G_OS_WIN32
 #include <sys/socket.h>
@@ -42,6 +43,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #endif
+#include <net/if.h>
 
 #include <glib-object.h>
 
