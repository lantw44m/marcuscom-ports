--- examples/renderdemo.c.orig	Mon Jul 19 20:53:12 2004
+++ examples/renderdemo.c	Mon Jul 19 20:53:28 2004
@@ -306,11 +306,12 @@
 		gpointer    data)
 {
   static GEnumClass *class = NULL;
+  GEnumValue *value;
 
   if (!class)
     class = g_type_class_ref (PANGO_TYPE_ELLIPSIZE_MODE);
   
-  GEnumValue *value = g_enum_get_value_by_nick (class, arg);
+  value = g_enum_get_value_by_nick (class, arg);
   if (!value)
     fail ("--ellipsize option must be one of none/start/middle/end");
 
