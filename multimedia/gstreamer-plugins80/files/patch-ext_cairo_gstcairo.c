--- ext/cairo/gstcairo.c.orig	Sun Jun 12 10:43:25 2005
+++ ext/cairo/gstcairo.c	Sun Jun 12 10:44:04 2005
@@ -46,5 +46,5 @@
   return TRUE;
 }
 
-GST_PLUGIN_DEFINE (GST_VERSION_MAJOR, GST_VERSION_MINOR, "timeoverlay",
-    "Time overlay", plugin_init, VERSION, GST_LICENSE, GST_PACKAGE, GST_ORIGIN)
+GST_PLUGIN_DEFINE (GST_VERSION_MAJOR, GST_VERSION_MINOR, "cairo",
+    "Cairo", plugin_init, VERSION, GST_LICENSE, GST_PACKAGE, GST_ORIGIN)
