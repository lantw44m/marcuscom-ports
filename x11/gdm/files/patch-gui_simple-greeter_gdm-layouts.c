--- gui/simple-greeter/gdm-layouts.c.orig	2009-07-06 17:10:45.000000000 -0400
+++ gui/simple-greeter/gdm-layouts.c	2009-07-06 17:10:58.000000000 -0400
@@ -52,7 +52,7 @@ init_xkl (void)
                 engine = xkl_engine_get_instance (GDK_DISPLAY ());
                 xkl_engine_backup_names_prop (engine);
                 config_registry = xkl_config_registry_get_instance (engine);
-                xkl_config_registry_load (config_registry);
+                xkl_config_registry_load (config_registry, TRUE);
 
                 initial_config = xkl_config_rec_new ();
                 if (!xkl_config_rec_get_from_backup (initial_config, engine)) {
