--- libgnomevfs/gnome-vfs-utils.c.orig	Sun May 22 23:18:12 2005
+++ libgnomevfs/gnome-vfs-utils.c	Sun May 22 23:18:55 2005
@@ -839,6 +839,7 @@ gnome_vfs_icon_path_from_filename (const
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
 		full_filename = g_build_filename (*temp_paths,
 						  "share",
+						  "gnome",
 						  "pixmaps",
 						  relative_filename,
 						  NULL);
