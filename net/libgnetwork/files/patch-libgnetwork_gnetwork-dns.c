--- libgnetwork/gnetwork-dns.c.orig	Thu Dec 11 21:25:54 2003
+++ libgnetwork/gnetwork-dns.c	Thu Dec 11 21:27:13 2003
@@ -33,6 +33,8 @@
 #include <time.h>
 #include <netdb.h>
 #include <string.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
