--- stickynotes/stickynotes.c.orig	Fri Jan 14 00:00:23 2005
+++ stickynotes/stickynotes.c	Fri Jan 14 00:05:24 2005
@@ -618,13 +618,13 @@
 {
 	WnckScreen *wnck_screen;
 	gint i;
-	
-	wnck_screen = wnck_screen_get_default ();
-	wnck_screen_force_update (wnck_screen);
 
 	/* Create a new XML document */
 	xmlDocPtr doc = xmlNewDoc("1.0");
 	xmlNodePtr root = xmlNewDocNode(doc, NULL, "stickynotes", NULL);
+	
+	wnck_screen = wnck_screen_get_default ();
+	wnck_screen_force_update (wnck_screen);
 
 	xmlDocSetRootElement(doc, root);
 	xmlNewProp(root, "version", VERSION);
@@ -633,6 +633,10 @@
 	for (i = 0; i < g_list_length(stickynotes->notes); i++) {
 		WnckWindow *wnck_win;
 		gulong xid = 0;
+		const gchar *title;
+		GtkTextBuffer *buffer;
+		GtkTextIter start, end;
+		gchar *body;
 
 		/* Access the current note in the list */
 		StickyNote *note = g_list_nth_data(stickynotes->notes, i);
@@ -661,13 +665,10 @@
 		}
 		
 		/* Retreive the title of the note */
-		const gchar *title = gtk_label_get_text(GTK_LABEL(note->w_title));
+		title = (const gchar *) gtk_label_get_text(GTK_LABEL(note->w_title));
 
 		/* Retrieve body contents of the note */
-		GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(note->w_body));
-		
-		GtkTextIter start, end;
-		gchar *body;
+		buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(note->w_body));
 		
 		gtk_text_buffer_get_bounds(buffer, &start, &end);
 		body = gtk_text_iter_get_text(&start, &end);
