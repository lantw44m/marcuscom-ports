--- daemon/misc.c.orig	Thu Jul 17 00:50:07 2003
+++ daemon/misc.c	Thu Jul 17 00:51:57 2003
@@ -23,6 +23,8 @@
 #include <signal.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/time.h>
+#include <sys/resource.h>
 #include <sys/wait.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
