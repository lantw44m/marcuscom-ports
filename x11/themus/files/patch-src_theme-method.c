--- src/theme-method.c.orig	Sun Apr 13 02:55:20 2003
+++ src/theme-method.c	Sun Apr 13 02:55:26 2003
@@ -537,8 +537,8 @@
 		return GNOME_VFS_OK;
 	}
 	else {
-		g_free (path);
 		GnomeThemeMetaInfo *theme;
+		g_free (path);
 		
 		theme = theme_meta_info_find (uri);
 		if (theme)
