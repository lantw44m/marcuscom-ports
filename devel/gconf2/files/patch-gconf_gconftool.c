--- gconftool.c.orig	Sun Jul  4 11:15:23 2004
+++ gconftool.c	Thu Jul  8 17:23:03 2004
@@ -460,8 +460,7 @@
 
 static int do_break_key(GConfEngine* conf, const gchar** args);
 static int do_break_directory(GConfEngine* conf, const gchar** args);
-static int do_makefile_install(GConfEngine* conf, const gchar** args);
-static int do_makefile_uninstall(GConfEngine* conf, const gchar** args);
+static int do_makefile_install(GConfEngine* conf, const gchar** args, gboolean unload);
 static int do_recursive_list(GConfEngine* conf, const gchar** args);
 static int do_dump_values(GConfEngine* conf, const gchar** args);
 static int do_all_pairs(GConfEngine* conf, const gchar** args);
@@ -888,7 +887,7 @@
   if (makefile_install_mode)
     {
       const gchar** args = poptGetArgs(ctx);
-      gint retval = do_makefile_install (conf, args);
+      gint retval = do_makefile_install (conf, args, FALSE);
       
       gconf_engine_unref (conf);
 
@@ -898,7 +897,7 @@
   if (makefile_uninstall_mode)
     {
       const gchar** args = poptGetArgs(ctx);
-      gint retval = do_makefile_uninstall (conf, args);
+      gint retval = do_makefile_install (conf, args, TRUE);
       
       gconf_engine_unref (conf);
 
@@ -3381,7 +3380,7 @@
     {
       GError* error = NULL;
 
-      if (!gconf_engine_associate_schema(conf, tmp->data, unload ? schema_name : NULL, &error))
+      if (!gconf_engine_associate_schema(conf, tmp->data, !unload ? schema_name : NULL, &error))
         {
           g_assert(error != NULL);
           
@@ -3708,7 +3707,7 @@
 }
 
 static int
-do_makefile_install(GConfEngine* conf, const gchar** args)
+do_makefile_install(GConfEngine* conf, const gchar** args, gboolean unload)
 {
   GError* err = NULL;
   
@@ -3720,39 +3719,7 @@
 
   while (*args)
     {
-      if (do_load_file(conf, LOAD_SCHEMA_FILE, FALSE, *args, NULL) != 0)
-        return 1;
-
-      ++args;
-    }
-
-  gconf_engine_suggest_sync(conf, &err);
-
-  if (err != NULL)
-    {
-      g_printerr (_("Error syncing config data: %s"),
-		  err->message);
-      g_error_free(err);
-      return 1;
-    }
-  
-  return 0;
-}
-
-static int
-do_makefile_uninstall(GConfEngine* conf, const gchar** args)
-{
-  GError* err = NULL;
-  
-  if (args == NULL)
-    {
-      g_printerr (_("Must specify some schema files to uninstall\n"));
-      return 1;
-    }
-
-  while (*args)
-    {
-      if (do_load_file(conf, LOAD_SCHEMA_FILE, TRUE, *args, NULL) != 0)
+      if (do_load_file(conf, LOAD_SCHEMA_FILE, unload, *args, NULL) != 0)
         return 1;
 
       ++args;
