--- plugins/vnc/vinagre-vnc-tunnel.c.orig	2010-01-28 10:23:44.000000000 +0900
+++ plugins/vnc/vinagre-vnc-tunnel.c	2010-01-28 10:24:39.000000000 +0900
@@ -21,6 +21,7 @@
 
 #include <config.h>
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include <unistd.h>
 #include <glib/gi18n.h>
 
