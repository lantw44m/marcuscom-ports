--- panels/info/cc-info-panel.c.orig	2011-02-02 20:05:49.000000000 +0100
+++ panels/info/cc-info-panel.c	2011-02-02 20:06:21.000000000 +0100
@@ -21,7 +21,12 @@
 
 #include "cc-info-panel.h"
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
