--- vfs-methods/themus/theme-method.c.orig	Thu May 22 01:42:21 2003
+++ vfs-methods/themus/theme-method.c	Thu May 22 01:44:13 2003
@@ -19,6 +19,7 @@
 
 #include <string.h>
 #include <errno.h>
+#include <libintl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 
@@ -528,8 +529,8 @@
 		return GNOME_VFS_OK;
 	}
 	else {
-		g_free (path);
 		GnomeThemeMetaInfo *theme;
+		g_free (path);
 		
 		theme = theme_meta_info_find (uri);
 		if (theme)
