--- giscanner/sourcescanner.py.orig	2013-06-28 21:08:22.000000000 +0200
+++ giscanner/sourcescanner.py	2013-06-28 21:08:54.000000000 +0200
@@ -281,8 +281,9 @@
         # some help from gcc from MinGW/Cygwin or so.
         # Note that the generated dumper program is
         # still built and linked by Visual C++.
-        if 'cl' in cpp_exec:
-            cpp_args = 'gcc'.split()
+        if 'clang' not in cpp_exec:
+            if 'cl' in cpp_exec:
+                cpp_args = 'gcc'.split()
         else:
             cpp_args = cpp_exec
         cpp_args += ['-E', '-C', '-I.', '-']
