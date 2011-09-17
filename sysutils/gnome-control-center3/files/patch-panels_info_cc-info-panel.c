--- panels/info/cc-info-panel.c.orig	2011-08-29 16:08:11.000000000 +0200
+++ panels/info/cc-info-panel.c	2011-09-17 14:35:53.000000000 +0200
@@ -23,7 +23,12 @@
 
 #include "cc-info-panel.h"
 
+#ifdef __linux__
 #include <sys/vfs.h>
+#else
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
 #include <polkit/polkit.h>
 
 #include <glib.h>
