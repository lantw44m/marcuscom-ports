--- giscanner/sourcescanner.py.orig	2011-09-03 20:42:14.000000000 +0200
+++ giscanner/sourcescanner.py	2011-11-04 13:36:04.000000000 +0100
@@ -274,7 +274,8 @@ class SourceScanner(object):
 
         defines = ['__GI_SCANNER__']
         undefs = []
-        cpp_args = [os.environ.get('CC', 'cc'), '-E', '-C', '-I.', '-']
+        cpp_args = os.environ.get('CC', 'cc').split()
+        cpp_args += ['-E', '-C', '-I.', '-']
 
         cpp_args += self._cpp_options
         proc = subprocess.Popen(cpp_args,
