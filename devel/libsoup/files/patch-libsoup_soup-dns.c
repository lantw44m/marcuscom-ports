--- libsoup/soup-dns.c.orig	Tue Dec  9 03:27:29 2003
+++ libsoup/soup-dns.c	Tue Dec  9 03:27:52 2003
@@ -17,6 +17,7 @@
 #include <unistd.h>
 #include <sys/select.h>
 #include <sys/types.h>
+#include <sys/uio.h>
 #include <sys/wait.h>
 
 #include <arpa/inet.h>
