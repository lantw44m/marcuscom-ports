--- libsoup/soup-dns.c.orig	Wed Dec 17 14:49:13 2003
+++ libsoup/soup-dns.c	Mon Dec 29 17:59:52 2003
@@ -17,10 +17,11 @@
 #include <unistd.h>
 #include <sys/select.h>
 #include <sys/types.h>
+#include <sys/uio.h>
 #include <sys/wait.h>
 
-#include <arpa/inet.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 #include "soup-dns.h"
 #include "soup-misc.h"
