--- null_applet/null_applet.c.orig	Tue Nov 23 18:17:07 2004
+++ null_applet/null_applet.c	Tue Nov 23 18:17:21 2004
@@ -126,6 +126,7 @@
 		gpointer     user_data)
 {
 	char *applet_list;
+	GtkWidget *dialog;
 
 	if (already_running)
 	{
@@ -136,8 +137,6 @@
 	g_warning ("was given applet to handle\n");
 
 	applet_list = get_all_applets ();
-
-	GtkWidget *dialog;
 
 	dialog = gtk_message_dialog_new_with_markup (NULL,
 			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
