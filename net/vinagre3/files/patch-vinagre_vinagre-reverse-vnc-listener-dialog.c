--- vinagre/vinagre-reverse-vnc-listener-dialog.c.orig	2011-09-17 23:36:02.000000000 +0200
+++ vinagre/vinagre-reverse-vnc-listener-dialog.c	2011-09-17 23:39:04.000000000 +0200
@@ -20,6 +20,8 @@
 
 #include <config.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
