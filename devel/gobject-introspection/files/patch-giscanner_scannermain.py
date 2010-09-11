--- giscanner/scannermain.py.orig	2010-09-11 16:30:31.000000000 +0000
+++ giscanner/scannermain.py	2010-09-11 16:32:10.000000000 +0000
@@ -246,8 +246,9 @@ def scanner_main(args):
     libraries = options.libraries
 
     if options.strip_prefix:
-        _error("""Option --strip-prefix has been replaced;
-see --identifier-prefix and --symbol-prefix.""")
+        print """g-ir-scanner: warning: Option --strip-prefix has been deprecated;
+see --identifier-prefix and --symbol-prefix."""
+        options.identifier_prefixes.append(options.strip_prefix)
 
     filenames = []
     for arg in args:
