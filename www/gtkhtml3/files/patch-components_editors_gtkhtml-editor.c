--- components/editor/gtkhtml-editor.c.orig	2009-09-29 10:28:17.000000000 +0200
+++ components/editor/gtkhtml-editor.c	2009-09-29 10:28:38.000000000 +0200
@@ -384,7 +384,7 @@ editor_method_event (GtkHTML *html,
 	guint signal_id;
 
 	/* GtkHTML event arguments are either NULL or a single string. */
-	if (G_VALUE_HOLDS (args, G_TYPE_STRING))
+	if (args && G_VALUE_HOLDS (args, G_TYPE_STRING))
 		string = g_value_get_string (args);
 
 	switch (event) {
