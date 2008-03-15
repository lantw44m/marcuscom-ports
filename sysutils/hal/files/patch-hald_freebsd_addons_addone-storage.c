--- addon-storage.c.orig	2008-03-15 14:26:23.000000000 -0400
+++ addon-storage.c	2008-03-15 14:26:25.000000000 -0400
@@ -150,6 +150,15 @@ hf_addon_storage_update (void)
   return has_media;
 }
 
+static void
+update_proc_title (const char *device, boolean polling_enabled)
+{
+  if (polling_enabled)
+    setproctitle("%s", device);
+  else
+    setproctitle("no polling on %s because it is explicitly disabled", device);
+}
+
 int
 main (int argc, char **argv)
 {
@@ -157,6 +166,7 @@ main (int argc, char **argv)
   char *removable;
   char *bus;
   char *driver;
+  boolean should_poll;
   DBusConnection *connection;
 
   if (! hfp_init(argc, argv))
@@ -186,9 +196,6 @@ main (int argc, char **argv)
   if (! addon.parent)
     goto end;
 
-  /* give a meaningful process title for ps(1) */
-  setproctitle("%s", addon.device_file);
-
   addon.is_cdrom = ! strcmp(drive_type, "cdrom");
   addon.is_scsi_removable = (! strcmp(bus, "scsi") ||
     (! strcmp(bus, "usb") && (! strcmp(driver, "da") || ! strcmp(driver, "sa") ||
@@ -226,23 +233,35 @@ main (int argc, char **argv)
 	    break;
 	}
 
-      has_media = hf_addon_storage_update();
-      if (has_media != addon.had_media)
-	{
-	  /*
-	   * FIXME: if the media was removed, we should force-unmount
-	   * all its child volumes (see linux2/addons/addon-storage.c).
-	   * However, currently (FreeBSD 6.0) umount -f is broken and
-	   * can cause kernel panics. When I tried to umount -f a
-	   * flash card after removing it, it failed with EAGAIN. It
-	   * continued to fail after I inserted the card. The system
-	   * then hung while rebooting and did not unmount my other
-	   * filesystems.
-	   */
-
-	  libhal_device_rescan(hfp_ctx, hfp_udi, &hfp_error);
-	  dbus_error_free(&hfp_error);
-	  addon.had_media = has_media;
+      should_poll = libhal_device_get_property_bool(hfp_ctx, hfp_udi, "storage.media_check_enabled", &hfp_error);
+      dbus_error_free(&hfp_error);
+      update_proc_title(addon.device_file, should_poll);
+
+      if (should_poll)
+        {
+          has_media = hf_addon_storage_update();
+          if (has_media != addon.had_media)
+	    {
+	      /*
+	       * FIXME: if the media was removed, we should force-unmount
+	       * all its child volumes (see linux2/addons/addon-storage.c).
+	       * However, currently (FreeBSD 6.0) umount -f is broken and
+	       * can cause kernel panics. When I tried to umount -f a
+	       * flash card after removing it, it failed with EAGAIN. It
+	       * continued to fail after I inserted the card. The system
+	       * then hung while rebooting and did not unmount my other
+	       * filesystems.
+	       */
+
+	      libhal_device_rescan(hfp_ctx, hfp_udi, &hfp_error);
+	      dbus_error_free(&hfp_error);
+	      addon.had_media = has_media;
+	    }
+        }
+      else
+        {
+          hfp_gettimeofday(&addon.next_update);
+	  hfp_timevaladd(&addon.next_update, &addon.update_interval);
 	}
     }
 
