--- giscanner/transformer.py.orig
+++ giscanner/transformer.py
@@ -80,6 +80,10 @@ class Transformer(object):
 
     def parse(self, symbols):
         for symbol in symbols:
+            ## WORKAROUND ##
+            # https://bugzilla.gnome.org/show_bug.cgi?id=550616
+            if symbol.ident in ['gst_g_error_get_type']:
+                continue
             node = self._traverse_one(symbol)
             if node:
                 self._append_new_node(node)
