--- src/netstatus-iface.c.orig	Wed Mar  3 08:07:35 2004
+++ src/netstatus-iface.c	Mon Mar  8 22:18:03 2004
@@ -32,12 +32,15 @@
 
 #include <libgnome/gnome-i18n.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/ioctl.h>
 #ifdef HAVE_SYS_SOCKIO_H
 #include <sys/sockio.h>
 #endif /* HAVE_SYS_SOCKIO_H */
 #include <net/if.h>
 #include <net/if_arp.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <errno.h>
 #include <unistd.h>
