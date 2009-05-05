--- gio/gunixresolver.c.orig	2009-05-05 17:12:54.000000000 -0400
+++ gio/gunixresolver.c	2009-05-05 17:15:05.000000000 -0400
@@ -24,6 +24,10 @@
 #include <glib.h>
 #include "glibintl.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <resolv.h>
 #include <stdio.h>
 #include <string.h>
