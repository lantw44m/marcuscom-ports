--- common/gdm-settings-direct.c.orig	2009-03-15 15:40:14.000000000 -0400
+++ common/gdm-settings-direct.c	2009-03-15 15:49:10.000000000 -0400
@@ -38,7 +38,7 @@
 #include "gdm-settings-utils.h"
 #include "gdm-settings-direct.h"
 
-static GHashTable      *schemas;
+static GHashTable      *schemas = NULL;
 static GdmSettings     *settings_object;
 
 static GdmSettingsEntry *
@@ -232,7 +232,8 @@ gdm_settings_direct_init (GdmSettings *s
         g_return_val_if_fail (file != NULL, FALSE);
         g_return_val_if_fail (root != NULL, FALSE);
 
-        g_assert (schemas == NULL);
+	if (schemas != NULL)
+		return TRUE;
 
         if (! gdm_settings_parse_schemas (file, root, &list)) {
                 g_warning ("Unable to parse schemas");
