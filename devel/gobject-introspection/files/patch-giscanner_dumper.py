--- giscanner/dumper.py.orig	2013-06-28 21:03:54.000000000 +0200
+++ giscanner/dumper.py	2013-06-28 21:04:31.000000000 +0200
@@ -90,8 +90,9 @@
         # the Microsoft compiler is used
         # (This is the other way to check whether Visual C++ is used subsequently)
         printf ("CC", self._compiler_cmd)
-        if 'cl' in self._compiler_cmd:
-            self._pkgconfig_msvc_flags = '--msvc-syntax'
+        if 'clang' not in self._compiler_cmd:
+            if 'cl' in self._compiler_cmd:
+                self._pkgconfig_msvc_flags = '--msvc-syntax'
         self._uninst_srcdir = os.environ.get(
             'UNINSTALLED_INTROSPECTION_SRCDIR')
         self._packages = ['gio-2.0 gmodule-2.0']
