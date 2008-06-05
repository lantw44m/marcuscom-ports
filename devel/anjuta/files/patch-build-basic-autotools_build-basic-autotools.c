--- plugins/build-basic-autotools/build-basic-autotools.c.orig	2008-06-05 16:17:30.000000000 +0200
+++ plugins/build-basic-autotools/build-basic-autotools.c	2008-06-05 16:17:48.000000000 +0200
@@ -41,6 +41,7 @@
 #include "executer.h"
 
 #include <sys/wait.h>
+#include <sys/signal.h>
 
 #define ICON_FILE "anjuta-build-basic-autotools-plugin-48.png"
 #define UI_FILE PACKAGE_DATA_DIR"/ui/anjuta-build-basic-autotools-plugin.ui"
