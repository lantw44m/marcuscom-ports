--- daemon/display.h.orig	Sat May  5 01:17:56 2007
+++ daemon/display.h	Sat May  5 01:18:27 2007
@@ -23,6 +23,8 @@
 
 #include <X11/Xlib.h> /* for Display */
 #include <X11/Xmd.h> /* for CARD32 */
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h> /* for in_addr */
 
 typedef struct _GdmDisplay GdmDisplay;
