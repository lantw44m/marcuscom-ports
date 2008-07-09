--- src/copy-theme-dialog.c	2008/01/31 03:10:09	1357
+++ src/copy-theme-dialog.c	2008/07/03 13:25:18	1463
@@ -21,12 +21,14 @@
 # include "config.h"
 #endif
 
+#include <limits.h>
+#include <string.h>
+
 #include <glib.h>
+#include <glib/gstdio.h>
 #include <glib/gi18n.h>
 #include <gtk/gtk.h>
 #include <gio/gio.h>
-#include <limits.h>
-#include <string.h>
 
 #include "copy-theme-dialog.h"
 
