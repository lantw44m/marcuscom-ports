--- src/journal.c.orig	Mon May 24 20:17:43 2004
+++ src/journal.c	Mon May 24 20:20:53 2004
@@ -414,6 +414,7 @@
 static void
 task_delete_memo_clicked_cb(GtkWidget * w, gpointer data) 
 {
+	GList * ctl;
 	Wiggy *wig = (Wiggy *) data;
 
 	/* its physically impossible to cut just the memo,
@@ -422,7 +423,7 @@
 
 	gtt_task_merge_up (wig->task);
 
-	GList * ctl = g_list_prepend(cutted_task_list, wig->task);
+	ctl = g_list_prepend(cutted_task_list, wig->task);
 	gtt_task_remove (wig->task);
 	cutted_task_list = ctl;
 }
@@ -657,6 +658,8 @@
 	if (!wig->hover_help_window)
 	{
 		char * msg = _("Left-click to bring up menu");
+		GtkWidget *label;
+		int px=0, py=0, rx=0, ry=0;
 
 		wig->hover_help_window = gtk_window_new(GTK_WINDOW_POPUP);
 		gtk_window_set_decorated (GTK_WINDOW(wig->hover_help_window), FALSE);
@@ -664,7 +667,7 @@
 		gtk_window_set_transient_for (GTK_WINDOW(wig->hover_help_window), 
 							 GTK_WINDOW(wig->top));
 
-		GtkWidget *label = gtk_label_new (msg);
+		label = gtk_label_new (msg);
 		gtk_container_add(GTK_CONTAINER(wig->hover_help_window), label);
 		gtk_widget_show (label);
 
@@ -672,7 +675,6 @@
 		gtk_window_set_focus (GTK_WINDOW(wig->top), GTK_WIDGET(wig->html));
 
 		/* Set up in initial default, so later move works. */
-		int px=0, py=0, rx=0, ry=0;
 		gtk_widget_get_pointer (GTK_WIDGET(wig->top), &px, &py);
 		gtk_window_get_position (GTK_WINDOW(wig->top), &rx, &ry);
 		gtk_window_move (GTK_WINDOW(wig->hover_help_window), rx+px, ry+py);
@@ -714,25 +716,28 @@
 perform_form_query (KvpFrame *kvpf)
 {
 	GList *results, *n;
+	char *user_debug;
+	char *query_string;
+	QofSqlQuery *q;
 
 	if (!kvpf) return NULL;
 
 	/* Allow the user to enable form debugging by adding the following html:
 	 * <input type="hidden" name="debug" value="1">
 	 */
-	char *user_debug = kvp_frame_get_string (kvpf, "debug");
+	user_debug = kvp_frame_get_string (kvpf, "debug");
 	if (user_debug)
 	{
 		printf ("Debug: HTML Form Input=%s\n", kvp_frame_to_string (kvpf));
 	}
 
-	QofSqlQuery *q = qof_sql_query_new();
+	q = qof_sql_query_new();
 
 	if (!book) book = qof_book_new();
 	qof_sql_query_set_book (q, book);
 	qof_sql_query_set_kvp (q, kvpf);
 
-	char *query_string = kvp_frame_get_string (kvpf, "query");
+	query_string = kvp_frame_get_string (kvpf, "query");
 	if (!query_string) return NULL;
 	if (0 == query_string[0]) return NULL;
 
