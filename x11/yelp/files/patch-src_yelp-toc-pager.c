--- src/yelp-toc-pager.c.orig	Tue Dec  2 12:21:22 2003
+++ src/yelp-toc-pager.c	Tue Dec  2 12:25:28 2003
@@ -367,7 +367,6 @@
     gnome_vfs_file_info_unref (file_info);
     gnome_vfs_directory_close (dir);
     g_slist_free_1 (first);
-    g_free (dirstr);
 
     if (priv->dir_pending)
 	return TRUE;
