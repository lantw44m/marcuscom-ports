--- libseed/seed-importer.c.orig	2009-08-22 14:10:19.000000000 -0400
+++ libseed/seed-importer.c	2009-08-22 14:17:07.000000000 -0400
@@ -20,8 +20,10 @@
 // TODO: Don't use GNU libc extension canonicalize_file_name, don't use realpath?
 #define _GNU_SOURCE
 
+#include <sys/param.h>
 #include <gio/gio.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include "seed-private.h"
 
@@ -637,8 +639,8 @@ seed_importer_handle_file (JSContextRef 
   JSValueRef js_file_dirname;
   JSObjectRef global, c_global;
   JSStringRef file_contents, file_name;
-  gchar *contents, *walk, *file_path, *canonical, *absolute_path;
-  gchar *normalized_path;
+  gchar *contents, *walk, *file_path, *canonical, *absolute_path, *normalp;
+  gchar normalized_path[PATH_MAX];
 
   file_path = g_build_filename (dir, file, NULL);
   canonical = seed_importer_canonicalize_path (file_path);
@@ -692,9 +694,9 @@ seed_importer_handle_file (JSContextRef 
 					g_path_get_dirname (file_path), NULL);
     }
 
-  normalized_path = canonicalize_file_name (absolute_path);
+  normalp = realpath (absolute_path, normalized_path);
 
-  js_file_dirname = seed_value_from_string (ctx, normalized_path, NULL);
+  js_file_dirname = seed_value_from_string (ctx, normalp, NULL);
 
   seed_object_set_property (nctx, global, "__script_path__", js_file_dirname);
 
