--- codegen/defsparser.py.orig	Thu Jun 15 14:13:39 2006
+++ codegen/defsparser.py	Thu Jun 15 14:13:50 2006
@@ -20,7 +20,7 @@ class IncludeParser(scmexpr.Parser):
         else:
             inc_path = [os.path.dirname(self.filename)] + include_path
             for filename in [os.path.join(path_entry, input_filename)
-                             for path_entry in include_path]:
+                             for path_entry in inc_path]:
                 if not os.path.exists(filename):
                     continue
                 # set self.filename to the include name, to handle recursive includes
