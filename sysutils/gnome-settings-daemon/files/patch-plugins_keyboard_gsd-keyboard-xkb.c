--- plugins/keyboard/gsd-keyboard-xkb.c.orig	2009-07-06 00:18:53.000000000 -0400
+++ plugins/keyboard/gsd-keyboard-xkb.c	2009-07-06 00:19:27.000000000 -0400
@@ -168,7 +168,7 @@ filter_xkb_config (void)
 	xkl_debug (100, "Filtering configuration against the registry\n");
 	if (!xkl_registry) {
 		xkl_registry = xkl_config_registry_get_instance (xkl_engine);
-		if (!xkl_config_registry_load (xkl_registry)) {
+		if (!xkl_config_registry_load (xkl_registry, TRUE)) {
 			g_object_unref (xkl_registry);
 			xkl_registry = NULL;
 			return FALSE;
