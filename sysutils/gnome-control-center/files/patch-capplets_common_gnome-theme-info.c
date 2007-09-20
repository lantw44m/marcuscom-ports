--- capplets/common/gnome-theme-info.c.orig	2007-09-20 12:12:10.000000000 -0400
+++ capplets/common/gnome-theme-info.c	2007-09-20 12:13:50.000000000 -0400
@@ -1845,7 +1845,7 @@ read_cursor_fonts (void)
     theme_info->thumbnail = gdk_pixbuf_new_from_file (filename, NULL);
     g_free (filename);
 
-    theme_info->name = g_build_filename (GNOMECC_DATA_DIR, builtins[i][0], NULL);
+    theme_info->name = g_build_filename (INSTALL_PREFIX, "share", builtins[i][0], NULL);
     theme_info->path = g_strdup (theme_info->name);
 
     if (!strcmp (theme_info->path, cursor_font))
