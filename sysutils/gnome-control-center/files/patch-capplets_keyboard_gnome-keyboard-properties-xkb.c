--- capplets/keyboard/gnome-keyboard-properties-xkb.c.orig	2009-07-07 14:41:53.000000000 -0400
+++ capplets/keyboard/gnome-keyboard-properties-xkb.c	2009-07-07 14:42:12.000000000 -0400
@@ -155,7 +155,7 @@ setup_xkb_tabs (GladeXML * dialog, GConf
 
 	engine = xkl_engine_get_instance (GDK_DISPLAY ());
 	config_registry = xkl_config_registry_get_instance (engine);
-	xkl_config_registry_load (config_registry);
+	xkl_config_registry_load (config_registry, TRUE);
 
 	gkbd_keyboard_config_init (&initial_config, xkb_gconf_client,
 				   engine);
