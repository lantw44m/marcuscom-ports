--- src/yelp-bookmarks.c.orig	Tue Jan  4 01:32:40 2005
+++ src/yelp-bookmarks.c	Tue Jan  4 01:33:18 2005
@@ -285,8 +285,9 @@
     GtkEntry *entry;
 
     if (id == GTK_RESPONSE_OK) {
+	    const gchar *title;
 	entry = GTK_ENTRY (g_object_get_data (G_OBJECT (dialog), "title_entry"));
-	const gchar *title = gtk_entry_get_text (entry);
+	title = gtk_entry_get_text (entry);
 
 	bookmarks_add_bookmark (uri, title, TRUE);
     }
