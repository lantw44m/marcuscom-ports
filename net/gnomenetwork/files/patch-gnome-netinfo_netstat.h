--- gnome-netinfo/netstat.h.orig	Mon Sep  1 02:24:37 2003
+++ gnome-netinfo/netstat.h	Mon Sep  1 02:27:08 2003
@@ -28,6 +28,10 @@
 #   define NETSTAT_PROTOCOL_FORMAT "%s %d %d %s %s %s %s %s" 
 #   define NETSTAT_ROUTE_FORMAT "%s %s %s %s %d %d %d %s" 
 #   define NETSTAT_MULTICAST_FORMAT "%s %d %s" 
+#elif defined(__FreeBSD__)
+#   define NETSTAT_PROTOCOL_FORMAT "%s %d %d %d.%d.%d.%d.%d %s %s"
+#   define NETSTAT_ROUTE_FORMAT "%s %s %s %d %d %s %d"
+#   define NETSTAT_MULTICAST_FORMAT "%s %d %s"
 
 #endif
 
