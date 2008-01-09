--- gio/glocalfile.c.orig	2007-12-22 15:19:11.000000000 -0500
+++ gio/glocalfile.c	2007-12-22 15:29:09.000000000 -0500
@@ -849,7 +849,11 @@ g_local_file_query_filesystem_info (GFil
 #endif
     }
 #ifdef USE_STATFS
+#ifndef __FreeBSD__
   fstype = get_fs_type (statfs_buffer.f_type);
+#else
+  fstype = statfs_buffer.f_fstypename;
+#endif
   if (fstype &&
       g_file_attribute_matcher_matches (attribute_matcher,
 					G_FILE_ATTRIBUTE_FILESYSTEM_TYPE))
