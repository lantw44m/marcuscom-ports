--- libtheme/gnome-theme-info.c.orig	Sun Apr 13 03:00:18 2003
+++ libtheme/gnome-theme-info.c	Sun Apr 13 03:00:31 2003
@@ -1620,7 +1620,7 @@
   gnome_vfs_uri_unref (top_theme_dir_uri);
 
   /* The weird /usr/share/icons */
-  top_theme_dir_uri = gnome_vfs_uri_new ("/usr/share/icons");
+  top_theme_dir_uri = gnome_vfs_uri_new ("%%X11BASE%%/share/icons");
   if (!gnome_vfs_uri_exists (top_theme_dir_uri))
     gnome_vfs_make_directory_for_uri (top_theme_dir_uri, 0775);
   result = add_top_icon_theme_dir_monitor (top_theme_dir_uri, &real_monitor_not_added, 2, NULL);
