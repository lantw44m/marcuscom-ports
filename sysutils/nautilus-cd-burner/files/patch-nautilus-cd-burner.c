--- nautilus-cd-burner.c.orig	Mon Jan 10 16:38:54 2005
+++ nautilus-cd-burner.c	Wed Jan 12 03:20:29 2005
@@ -23,6 +23,8 @@
  *          Bastien Nocera <hadess@hadess.net>
  */
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <gtk/gtk.h>
 #include <gtk/gtkfilesel.h>
 #include <gtk/gtkseparatormenuitem.h>
@@ -720,8 +722,19 @@
 		}
 
 		if (res == NAUTILUS_BURN_RECORDER_RESULT_RETRY) {
-			g_free (filename);
-			filename = g_build_filename (g_get_tmp_dir (), "image.iso.XXXXXX", NULL);
+			gchar *path1;
+
+			path1 = g_strdup_printf ("%s/.ncb", g_get_home_dir());
+
+			if (!g_file_test (path1, G_FILE_TEST_EXISTS)) {
+				mkdir (path1, 0700);
+			}
+
+			if (filename != NULL) {
+				g_free (filename);
+			}
+			filename = g_build_filename (path1, "image.iso.XXXXXX", NULL);
+			g_free (path1);
 			fd = g_mkstemp(filename);
 			close (fd);
 
