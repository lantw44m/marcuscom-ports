--- src/netstatus-iface.c.orig	Tue Jan 20 10:00:20 2004
+++ src/netstatus-iface.c	Wed Feb  4 15:39:09 2004
@@ -32,9 +32,12 @@
 
 #include <libgnome/gnome-i18n.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
 #include <net/if_arp.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <unistd.h>
