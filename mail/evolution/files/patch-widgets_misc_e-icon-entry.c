--- widgets/misc/e-icon-entry.c.orig	Fri Jun 30 17:03:34 2006
+++ widgets/misc/e-icon-entry.c	Sun Jul 16 19:06:58 2006
@@ -37,8 +37,10 @@
 #include "e-icon-entry.h"
 
 #include <gtk/gtkentry.h>
+#include <gtk/gtkeventbox.h>
 #include <gtk/gtkbox.h>
 #include <gtk/gtkhbox.h>
+#include <gtk/gtkimage.h>
 
 #define E_ICON_ENTRY_GET_PRIVATE(object)(G_TYPE_INSTANCE_GET_PRIVATE ((object), E_TYPE_ICON_ENTRY, EIconEntryPrivate))
 
