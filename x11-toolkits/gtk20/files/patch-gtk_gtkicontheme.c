--- gtk/gtkicontheme.c.orig	Mon Jan  3 09:44:33 2005
+++ gtk/gtkicontheme.c	Sat Jan  8 19:59:53 2005
@@ -568,7 +568,7 @@
   xdg_data_dirs = g_get_system_data_dirs ();
   for (i = 0; xdg_data_dirs[i]; i++) ;
 
-  priv->search_path_len = i + 2;
+  priv->search_path_len = (i * 2) + 2;
 #ifdef G_OS_UNIX
   priv->search_path_len++;
 #endif
@@ -579,8 +579,10 @@
   priv->search_path[i++] = g_build_filename (g_get_home_dir (), ".icons", NULL);
   priv->search_path[i++] = g_build_filename (g_get_user_data_dir (), "icons", NULL);
   
-  for (j = 0; xdg_data_dirs[j]; j++) 
+  for (j = 0; xdg_data_dirs[j]; j++) {
     priv->search_path[i++] = g_build_filename (xdg_data_dirs[j], "icons", NULL);
+    priv->search_path[i++] = g_build_filename (xdg_data_dirs[j], "pixmaps", NULL);
+  }
 
 #ifdef G_OS_UNIX
   priv->search_path[i++] = g_strdup ("/usr/share/pixmaps");
