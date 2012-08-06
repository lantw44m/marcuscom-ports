--- tools/make_schema.py.orig	2012-08-06 18:41:04.000000000 +0200
+++ tools/make_schema.py	2012-08-06 18:41:15.000000000 +0200
@@ -58,7 +58,7 @@
             schemalist.appendChild(key)
             self._append_children_element_value_pairs(
                 doc, key, [('default',
-                            getattr(setting.gvariant, "print_")(False)),
+                            getattr(setting.gvariant, "print")(False)),
                            ('_summary', setting.short_desc),
                            ('_description', setting.long_desc)])
 
