--- gui/gdmcommon.c.orig	Tue Oct 24 00:47:40 2006
+++ gui/gdmcommon.c	Tue Oct 24 00:51:13 2006
@@ -626,13 +626,14 @@ filter_watch (GdkXEvent *xevent, GdkEven
 static void
 error_dialog (void)
 {
-	GtkWidget *dialog = gtk_message_dialog_new (NULL,
+/*	GtkWidget *dialog = gtk_message_dialog_new (NULL,
 						    GTK_DIALOG_MODAL,
 						    GTK_MESSAGE_ERROR,
 						    GTK_BUTTONS_OK,
 						    _("Assistive technology support has been requested for this session, but the accessibility registry was not found.  Please ensure that the AT-SPI package is installed. Your session has been started without assistive technology support."));
 	gtk_dialog_run (GTK_DIALOG (dialog));
 	gtk_widget_destroy (dialog);
+	*/
 }
 
 
