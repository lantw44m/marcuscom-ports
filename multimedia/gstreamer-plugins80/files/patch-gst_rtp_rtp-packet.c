--- gst/rtp/rtp-packet.c.orig	Sat Nov 15 01:59:32 2003
+++ gst/rtp/rtp-packet.c	Sat Nov 15 01:59:44 2003
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <glib.h>
 
