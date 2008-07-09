--- plparse/totem-pl-parser.c	2008/06/10 12:46:22	139
+++ plparse/totem-pl-parser.c	2008/07/03 13:02:07	148
@@ -97,6 +97,7 @@
 
 #include <string.h>
 #include <glib.h>
+#include <glib/gstdio.h>
 #include <glib/gi18n-lib.h>
 #include <gio/gio.h>
 
@@ -644,7 +645,7 @@
 		char *path;
 
 		path = g_file_get_path (file);
-		if (stat (path, &buf) == 0 && S_ISBLK (buf.st_mode)) {
+		if (g_stat (path, &buf) == 0 && S_ISBLK (buf.st_mode)) {
 			g_free (path);
 			return g_strdup (BLOCK_DEVICE_TYPE);
 		}
