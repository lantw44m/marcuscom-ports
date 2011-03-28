--- gnome-settings-daemon/gnome-settings-module.c.orig	2011-03-28 18:38:07.000000000 -0400
+++ gnome-settings-daemon/gnome-settings-module.c	2011-03-28 18:31:50.000000000 -0400
@@ -92,7 +92,7 @@ gnome_settings_module_unload (GTypeModul
 
         g_debug ("Unloading %s", module->path);
 
-        g_module_close (module->library);
+        /*g_module_close (module->library);*/
 
         module->library = NULL;
         module->type = 0;
