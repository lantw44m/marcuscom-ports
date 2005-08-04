--- libgnomevfs/gnome-vfs-utils.c.orig	Sun May  8 09:04:05 2005
+++ libgnomevfs/gnome-vfs-utils.c	Thu Aug  4 01:58:06 2005
@@ -839,6 +839,7 @@ gnome_vfs_icon_path_from_filename (const
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
 		full_filename = g_build_filename (*temp_paths,
 						  "share",
+						  "gnome",
 						  "pixmaps",
 						  relative_filename,
 						  NULL);
@@ -1954,6 +1955,7 @@ _gnome_vfs_uri_resolve_all_symlinks_uri 
 	GnomeVFSResult res;
 	char *p;
 	int n_followed_symlinks;
+	int fully_qualified = 0;
 
 	/* Ref the original uri so we don't lose it */
 	uri = gnome_vfs_uri_ref (uri);
@@ -1963,6 +1965,8 @@ _gnome_vfs_uri_resolve_all_symlinks_uri 
 	info = gnome_vfs_file_info_new ();
 
 	p = uri->text;
+	if (*p == GNOME_VFS_URI_PATH_CHR)
+		fully_qualified++;
 	n_followed_symlinks = 0;
 	while (*p != 0) {
 		while (*p == GNOME_VFS_URI_PATH_CHR)
@@ -1972,7 +1976,11 @@ _gnome_vfs_uri_resolve_all_symlinks_uri 
 
 		new_uri = gnome_vfs_uri_dup (uri);
 		g_free (new_uri->text);
-		new_uri->text = g_strndup (uri->text, p - uri->text);
+		if (fully_qualified-- > 0)
+			new_uri->text = g_strdup_printf ("%c",
+					GNOME_VFS_URI_PATH_CHR);
+		else
+			new_uri->text = g_strndup (uri->text, p - uri->text);
 		
 		gnome_vfs_file_info_clear (info);
 		res = gnome_vfs_get_file_info_uri (new_uri, info, GNOME_VFS_FILE_INFO_DEFAULT);
