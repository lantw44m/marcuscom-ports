--- libgnetwork/gnetwork-ip-address.c.orig	Thu Dec 11 23:26:37 2003
+++ libgnetwork/gnetwork-ip-address.c	Thu Dec 11 23:27:00 2003
@@ -26,6 +26,8 @@
 #include "gnetwork-ip-address.h"
 #include "gnetwork-utils.h"
 
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <string.h>
