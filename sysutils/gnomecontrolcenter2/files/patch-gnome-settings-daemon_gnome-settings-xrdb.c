--- gnome-settings-daemon/gnome-settings-xrdb.c.orig	Fri May  9 11:55:44 2003
+++ gnome-settings-daemon/gnome-settings-xrdb.c	Fri May  9 11:55:58 2003
@@ -251,6 +251,7 @@
 append_xresources (GString *string, GError **error)
 {
 	const char* home_path;
+	char *xresources;
 
 	g_return_if_fail (string != NULL);
 
@@ -259,7 +260,7 @@
 		g_warning (_("Cannot determine user's home directory"));
 		return;
 	}
-	char *xresources = g_build_filename (home_path, USER_X_RESOURCES, NULL);
+	xresources = g_build_filename (home_path, USER_X_RESOURCES, NULL);
 	if (g_file_test (xresources, G_FILE_TEST_EXISTS)) {
 		append_file (xresources, string, error);
 		if (*error) {
