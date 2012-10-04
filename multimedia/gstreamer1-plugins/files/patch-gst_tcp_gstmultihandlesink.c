--- gst/tcp/gstmultihandlesink.c.orig	2012-06-06 10:25:28.000000000 +0200
+++ gst/tcp/gstmultihandlesink.c	2012-06-06 10:26:43.000000000 +0200
@@ -104,6 +104,8 @@
 #include "config.h"
 #endif
 
+#include <sys/socket.h>
+
 #include <gst/gst-i18n-plugin.h>
 
 #include "gstmultihandlesink.h"
