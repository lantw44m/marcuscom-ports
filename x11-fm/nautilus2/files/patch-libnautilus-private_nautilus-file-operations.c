--- libnautilus-private/nautilus-file-operations.c.orig	Sun Jul 31 13:44:00 2005
+++ libnautilus-private/nautilus-file-operations.c	Sun Jul 31 14:23:47 2005
@@ -2453,12 +2453,21 @@ nautilus_file_operations_new_file (GtkWi
 				   NautilusNewFileCallback done_callback,
 				   gpointer data)
 {
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
+                                            "nautilus-sourceXXXXXX", NULL);
 	fd = mkstemp (source_file_str);
 	if (fd == -1) {
 		(*done_callback) (NULL, data);
@@ -2486,6 +2495,8 @@ nautilus_file_operations_new_file (GtkWi
 							 done_callback,
 							 data);
 
+	gnome_vfs_uri_unref (parent_uri);
+	g_free (source_file_str);
 	g_free (source_file_uri);
 	g_free (target_filename);
 }
