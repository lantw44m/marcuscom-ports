--- libsoup/soup-address.c.orig	Mon Dec 29 17:47:27 2003
+++ libsoup/soup-address.c	Mon Dec 29 17:54:11 2003
@@ -18,9 +18,9 @@
 #include <sys/wait.h>
 #include <signal.h>
 
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
-#include <netinet/in.h>
 
 #include "soup-address.h"
 #include "soup-dns.h"
