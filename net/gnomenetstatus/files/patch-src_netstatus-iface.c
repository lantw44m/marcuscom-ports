--- src/netstatus-iface.c.orig	Fri Dec  5 18:27:45 2003
+++ src/netstatus-iface.c	Fri Dec  5 18:35:36 2003
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
@@ -646,7 +649,11 @@
   strncpy (if_req.ifr_name, iface->priv->name, IF_NAMESIZE - 1);
   if_req.ifr_name [IF_NAMESIZE - 1] = '\0';
   if (mask && ioctl (fd, SIOCGIFNETMASK, &if_req) == 0)
+#if !defined(__FreeBSD__)
     *mask = g_strdup (inet_ntoa (((struct sockaddr_in *) &if_req.ifr_netmask)->sin_addr));
+#else
+    *mask = g_strdup (inet_ntoa (((struct sockaddr_in *) &if_req.ifr_addr)->sin_addr));
+#endif
 
   close (fd);
 
@@ -925,6 +932,7 @@
 				char           **hw_addr)
 				
 {
+#ifdef SIOCGIFHWADDR
   static struct HwType *hw_type = NULL;
   struct ifreq          if_req;
   int                   fd;
@@ -973,6 +981,9 @@
     *hw_addr = hw_type->print_hw_addr (if_req.ifr_hwaddr.sa_data);
 
   return hw_type;
+#else
+  return NULL;
+#endif
 }
 
 gboolean
