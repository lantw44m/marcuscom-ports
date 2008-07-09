--- libnautilus-private/nautilus-emblem-utils.c	2008/07/03 13:30:04	14318
+++ libnautilus-private/nautilus-emblem-utils.c	2008/07/03 13:33:17	14319
@@ -30,12 +30,17 @@
 #include <string.h>
 #include <time.h>
 #include <unistd.h>
-#include "nautilus-file.h"
+
+#include <glib.h>
+#include <glib/gstdio.h>
+#include <glib/gi18n.h>
+#include <gtk/gtk.h>
+
 #include <eel/eel-glib-extensions.h>
 #include <eel/eel-gdk-pixbuf-extensions.h>
 #include <eel/eel-stock-dialogs.h>
-#include <glib/gi18n.h>
-#include <gtk/gtk.h>
+
+#include "nautilus-file.h"
 #include "nautilus-emblem-utils.h"
 
 #define EMBLEM_NAME_TRASH   "emblem-trash"
