--- parse.c.orig	Sun Oct 16 13:09:39 2005
+++ parse.c	Sat Sep  2 14:09:44 2006
@@ -707,6 +707,16 @@ static void _do_parse_libs (Package *pkg
           i++;
           g_free(framework);
         }
+      else if ((strcmp("-Wl,--rpath",p) == 0 || strcmp("-Wl,-rpath",p) == 0) &&
+        i+1 < argc)
+        {
+          gchar *rpath = trim_string (argv[i+1]);
+
+          pkg->other_libs = g_slist_prepend (pkg->other_libs,
+                                             g_strconcat(arg, " ", rpath, NULL));
+          i++;
+          g_free(rpath);
+        }
       else
         {
           if (*arg != '\0')
