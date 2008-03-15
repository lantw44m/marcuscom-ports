--- hald/freebsd/hf-util.c.orig	2008-03-15 14:27:25.000000000 -0400
+++ hald/freebsd/hf-util.c	2008-03-15 14:27:29.000000000 -0400
@@ -263,7 +263,7 @@ hf_device_set_udi (HalDevice *device, co
   udi = g_strdup_vprintf(format, args);
   va_end(args);
 
-  safe_str = hf_str_no_slashes(udi);
+  safe_str = hf_str_escape(udi);
   g_free(udi);
 
   hf_device_set_full_udi(device, "/org/freedesktop/Hal/devices/%s", safe_str);
@@ -675,14 +675,18 @@ hf_device_store_match (HalDeviceStore *s
 }
 
 char *
-hf_str_no_slashes (const char *str)
+hf_str_escape (const char *str)
 {
   char *safe_str;
 
   g_return_val_if_fail(str != NULL, NULL);
 
   safe_str = g_strdup(str);
-  safe_str = g_strdelimit(safe_str, "/", '_');
+  g_strcanon(safe_str,
+             "_"
+	     "abcdefghijklmnopqrstuvwxyz"
+	     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
+	     "1234567890", '_');
 
   return safe_str;
 }
