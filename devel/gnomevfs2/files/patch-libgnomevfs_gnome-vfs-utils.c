--- libgnomevfs/gnome-vfs-utils.c.orig	Wed Jun  8 03:19:54 2005
+++ libgnomevfs/gnome-vfs-utils.c	Tue Sep 20 01:39:33 2005
@@ -839,6 +839,7 @@ gnome_vfs_icon_path_from_filename (const
 	for (temp_paths = paths; *temp_paths != NULL; temp_paths++) {
 		full_filename = g_build_filename (*temp_paths,
 						  "share",
+						  "gnome",
 						  "pixmaps",
 						  relative_filename,
 						  NULL);
