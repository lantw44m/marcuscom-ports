--- src/nautilus-bookmark-list.c.orig	Sun Jul  3 18:33:29 2005
+++ src/nautilus-bookmark-list.c	Sun Jul  3 18:33:40 2005
@@ -449,6 +449,7 @@ static void
 nautilus_bookmark_list_load_file (NautilusBookmarkList *bookmarks)
 {
 	char *filename, *contents;
+	GError **error = NULL;
 
 	filename = nautilus_bookmark_list_get_file_path ();
 
@@ -462,7 +463,6 @@ nautilus_bookmark_list_load_file (Nautil
 	}
 
 	/* Read new list from file */
-	GError **error = NULL;
 	if (g_file_get_contents (filename, &contents, NULL, error)) {
         	char **lines;
       		int i;
