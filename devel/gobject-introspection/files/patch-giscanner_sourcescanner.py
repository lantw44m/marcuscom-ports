--- giscanner/sourcescanner.py.orig	2011-09-03 20:42:14.000000000 +0200
+++ giscanner/sourcescanner.py	2011-10-04 13:48:48.000000000 +0200
@@ -274,7 +274,7 @@
 
         defines = ['__GI_SCANNER__']
         undefs = []
-        cpp_args = [os.environ.get('CC', 'cc'), '-E', '-C', '-I.', '-']
+        cpp_args = ['%%CC%%', '-E', '-C', '-I.', '-']
 
         cpp_args += self._cpp_options
         proc = subprocess.Popen(cpp_args,
