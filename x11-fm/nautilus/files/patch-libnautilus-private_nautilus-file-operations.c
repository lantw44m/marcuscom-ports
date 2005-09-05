--- libnautilus-private/nautilus-file-operations.c.orig	Thu Aug 25 10:28:10 2005
+++ libnautilus-private/nautilus-file-operations.c	Mon Sep  5 17:09:55 2005
@@ -2481,12 +2481,22 @@
 				   gpointer data)
 {
 	struct NewFileData *new_data;
-	char source_file_str[] = "/tmp/nautilus-sourceXXXXXX";
+	char *source_file_str;
 	char *source_file_uri;
+	GnomeVFSURI *parent_uri;
 	FILE *source_file;
 	char *target_filename;
 	int fd;
 
+	parent_uri = gnome_vfs_uri_new (parent_dir);
+	if (parent_uri == NULL) {
+		(*done_callback) (NULL, data);
+		return;
+	}
+
+	source_file_str = g_build_filename (gnome_vfs_uri_get_path (parent_uri),
+						"nautilus-sourceXXXXXX", NULL);
+
 	fd = mkstemp (source_file_str);
 	if (fd == -1) {
 		(*done_callback) (NULL, data);
@@ -2518,6 +2528,8 @@
 							 new_file_from_temp_callback,
 							 new_data);
 
+	gnome_vfs_uri_unref (parent_uri);
+	g_free (source_file_str);
 	g_free (source_file_uri);
 	g_free (target_filename);
 }
