--- calendar/gui/e-cal-config.c.orig	Wed Dec  8 03:11:02 2004
+++ calendar/gui/e-cal-config.c	Wed Dec  8 03:12:13 2004
@@ -26,11 +26,13 @@
 #include <gtk/gtkwidget.h>
 #include "e-cal-config.h"
 
+#include <sys/types.h>
+
 static GObjectClass *ecp_parent_class;
 static GObjectClass *ecph_parent_class;
 
 struct _ECalConfigPrivate {
-	ulong source_changed_id;
+	unsigned long source_changed_id;
 };
 
 #define _PRIVATE(o) (g_type_instance_get_private ((GTypeInstance *)o, e_cal_config_get_type ()))
