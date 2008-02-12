--- libgnome-desktop/gnome-bg.c.orig	2008-02-12 14:33:11.000000000 -0500
+++ libgnome-desktop/gnome-bg.c	2008-02-12 14:34:12.000000000 -0500
@@ -1076,10 +1076,11 @@ get_mtime (const char *uri)
 		file = g_file_new_for_uri (uri);
 		info = g_file_query_info (file, G_FILE_ATTRIBUTE_TIME_MODIFIED,
 					  G_FILE_QUERY_INFO_NONE, NULL, NULL);
-		if (info)
+		if (info) {
 			mtime = g_file_info_get_attribute_uint64 (info,
 								  G_FILE_ATTRIBUTE_TIME_MODIFIED);
-		g_object_unref (info);
+			g_object_unref (info);
+		}
 		g_object_unref (file);
 	}
 	
