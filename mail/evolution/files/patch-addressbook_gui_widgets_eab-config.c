--- addressbook/gui/widgets/eab-config.c.orig	Tue Nov 23 16:01:13 2004
+++ addressbook/gui/widgets/eab-config.c	Tue Nov 23 16:03:20 2004
@@ -23,13 +23,15 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
+
 #include "eab-config.h"
 
 static GObjectClass *ecp_parent_class;
 static GObjectClass *ecph_parent_class;
 
 struct _EABConfigPrivate {
-	ulong source_changed_id;
+	u_long source_changed_id;
 };
 
 #define _PRIVATE(o) (g_type_instance_get_private((GTypeInstance *)o, eab_config_get_type()))
