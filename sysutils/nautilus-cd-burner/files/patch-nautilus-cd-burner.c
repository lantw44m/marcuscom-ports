--- nautilus-cd-burner.c.orig	Sun Sep 19 17:44:15 2004
+++ nautilus-cd-burner.c	Sun Oct 31 02:11:52 2004
@@ -21,6 +21,8 @@
   
    Authors: Alexander Larsson <alexl@redhat.com>
 */
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <gtk/gtk.h>
 #include <gtk/gtkfilesel.h>
 #include <gtk/gtkseparatormenuitem.h>
@@ -632,8 +634,17 @@
 		}
 
 		if (res == RESULT_RETRY) {
+			const char *path1;
+
+			g_free (path1);
+			path1 = g_strdup_printf("%s/.ncb", g_get_home_dir());
+
+			if (!g_file_test (path1, G_FILE_TEST_EXISTS)) {
+				mkdir (path1, 0700);
+			}
+
 			g_free (filename);
-			filename = g_build_filename (g_get_tmp_dir (), "image.iso.XXXXXX", NULL);
+			filename = g_build_filename (path1, "image.iso.XXXXXX", NULL);
 			fd = g_mkstemp(filename);
 			close (fd);
 
