--- hald/freebsd/addons/addon-storage.c.orig	2008-03-18 03:37:34.000000000 -0400
+++ hald/freebsd/addons/addon-storage.c	2008-03-18 03:34:58.000000000 -0400
@@ -202,6 +202,10 @@ main (int argc, char **argv)
     ! strcmp(driver, "cd")))) && ! strcmp(removable, "true");
   addon.had_media = hf_addon_storage_update();
 
+  if (!libhal_device_addon_is_ready(hfp_ctx, hfp_udi, &hfp_error))
+    goto end;
+  dbus_error_free(&hfp_error);
+
   connection = libhal_ctx_get_dbus_connection(hfp_ctx);
   assert(connection != NULL);
 
