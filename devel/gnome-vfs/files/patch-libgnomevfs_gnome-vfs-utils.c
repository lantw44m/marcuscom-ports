--- libgnomevfs/gnome-vfs-utils.c.orig	Sat Jul 31 17:54:38 2004
+++ libgnomevfs/gnome-vfs-utils.c	Sat Jul 31 17:56:05 2004
@@ -797,7 +797,9 @@
 	
 #if HAVE_STATVFS
 	statfs_result = statvfs (unescaped_path, &statfs_buffer);
+#define statfs_bsize f_frsize
 #else
+#define statfs_bsize f_bsize
 #if STATFS_ARGS == 2
 	statfs_result = statfs (unescaped_path, &statfs_buffer);   
 #elif STATFS_ARGS == 4
@@ -839,7 +841,7 @@
 #else 	
 	g_free (unescaped_path);
 #endif
-	block_size = statfs_buffer.f_bsize; 
+	block_size = statfs_buffer.statfs_bsize; 
 	free_blocks = statfs_buffer.f_bavail;
 
 	*size = block_size * free_blocks;
@@ -867,7 +869,7 @@
 	paths = g_strsplit (gnome_var, ":", 0); 
 
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
-		full_filename = g_strconcat (*temp_paths, "/share/pixmaps/", relative_filename, NULL);
+		full_filename = g_strconcat (*temp_paths, "/share/gnome/pixmaps/", relative_filename, NULL);
 		if (g_file_test (full_filename, G_FILE_TEST_EXISTS)) {
 			g_strfreev (paths);
 			return full_filename;
