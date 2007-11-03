--- gui/simple-chooser/gdm-host-chooser-widget.c.orig	2007-11-02 20:25:18.000000000 -0400
+++ gui/simple-chooser/gdm-host-chooser-widget.c	2007-11-02 20:26:16.000000000 -0400
@@ -26,6 +26,8 @@
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
