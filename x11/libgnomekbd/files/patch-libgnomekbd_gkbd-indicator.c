--- libgnomekbd/gkbd-indicator.c.orig	2009-07-06 00:27:46.000000000 -0400
+++ libgnomekbd/gkbd-indicator.c	2009-07-06 00:27:57.000000000 -0400
@@ -717,7 +717,7 @@ gkbd_indicator_global_init (void)
 	globals.registry =
 	    xkl_config_registry_get_instance (globals.engine);
 
-	xkl_config_registry_load (globals.registry);
+	xkl_config_registry_load (globals.registry, TRUE);
 
 	gconf_client = gconf_client_get_default ();
 
