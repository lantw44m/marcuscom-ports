--- libgnomevfs/gnome-vfs-utils.c.orig	Thu Feb 10 05:00:21 2005
+++ libgnomevfs/gnome-vfs-utils.c	Mon Feb 21 16:32:20 2005
@@ -880,7 +880,7 @@ gnome_vfs_icon_path_from_filename (const
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (g_file_test (full_filename, G_FILE_TEST_EXISTS)) {
 			g_strfreev (paths);
 			return full_filename;
@@ -1083,6 +1083,9 @@ gnome_vfs_read_entire_file (const char *
 		total_bytes_read += bytes_read;
 	} while (result == GNOME_VFS_OK);
 
+	buffer = g_realloc (buffer, total_bytes_read + 1);
+	buffer[total_bytes_read] = '\0';
+
 	/* Close the file. */
 	result = gnome_vfs_close (handle);
 	if (result != GNOME_VFS_OK) {
@@ -1092,7 +1095,7 @@ gnome_vfs_read_entire_file (const char *
 
 	/* Return the file. */
 	*file_size = total_bytes_read;
-	*file_contents = g_realloc (buffer, total_bytes_read);
+	*file_contents = g_realloc (buffer, total_bytes_read + 1);
 	return GNOME_VFS_OK;
 }
 
