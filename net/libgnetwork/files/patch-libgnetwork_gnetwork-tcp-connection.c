--- libgnetwork/gnetwork-tcp-connection.c.orig	Thu Dec 11 23:27:47 2003
+++ libgnetwork/gnetwork-tcp-connection.c	Thu Dec 11 23:28:04 2003
@@ -42,6 +42,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <string.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/time.h>
 #include <sys/types.h>
