--- daemon/auth.c.orig	Thu Jan  8 14:36:16 2004
+++ daemon/auth.c	Thu Jan  8 14:38:35 2004
@@ -22,6 +22,7 @@
 #include <config.h>
 #include <libgnome/libgnome.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <unistd.h>
 #include <sys/stat.h>
 #include <fcntl.h>
