--- gnome-netinfo/info.c.orig	Tue Jun  3 04:51:08 2003
+++ gnome-netinfo/info.c	Tue Jun  3 04:52:27 2003
@@ -26,6 +26,10 @@
 #endif
 
 
+#ifdef __FreeBSD__
+#  include <netinet/in.h>
+#endif
+
 #include <sys/socket.h>	/* basic socket definitions */
 #include <arpa/inet.h>	/* inet(3) functions */
 #include <sys/un.h>	/* for Unix domain sockets */
