--- libanjuta/anjuta-launcher.c.orig	Sun May 22 21:29:10 2005
+++ libanjuta/anjuta-launcher.c	Sun May 22 21:30:08 2005
@@ -24,8 +24,12 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <signal.h>
+#if defined(__FreeBSD__)
+#include <libutil.h>
+#else
 #ifndef sun
 #include <pty.h>
+#endif
 #endif
 #include <assert.h>
 #include <gnome.h>
