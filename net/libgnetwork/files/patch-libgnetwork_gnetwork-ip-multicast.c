--- libgnetwork/gnetwork-ip-multicast.c.orig	Thu Dec 11 23:27:11 2003
+++ libgnetwork/gnetwork-ip-multicast.c	Thu Dec 11 23:27:32 2003
@@ -34,8 +34,9 @@
 
 #include <glib/gi18n.h>
 
-#include <arpa/inet.h>
 #include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <string.h>
