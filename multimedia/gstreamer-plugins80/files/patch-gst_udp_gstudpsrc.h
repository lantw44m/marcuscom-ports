--- gst/udp/gstudpsrc.h.orig	Wed Dec 11 13:49:50 2002
+++ gst/udp/gstudpsrc.h	Wed Dec 11 13:50:00 2002
@@ -33,6 +33,7 @@
 #include <sys/types.h>
 #include <netdb.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <fcntl.h>
 #include "gstudp.h"
 
