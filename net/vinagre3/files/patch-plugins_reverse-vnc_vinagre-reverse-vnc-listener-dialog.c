--- plugins/reverse-vnc/vinagre-reverse-vnc-listener-dialog.c.orig	2011-03-29 21:27:53.000000000 -0500
+++ plugins/reverse-vnc/vinagre-reverse-vnc-listener-dialog.c	2011-03-29 21:28:10.000000000 -0500
@@ -20,6 +20,8 @@
 
 #include <config.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
