--- libnautilus-private/nautilus-program-chooser.c.orig	Thu Jan 22 18:01:21 2004
+++ libnautilus-private/nautilus-program-chooser.c	Thu Jan 22 18:01:28 2004
@@ -1610,11 +1610,11 @@
 	                                 _("_Associate Application"), GTK_STOCK_CANCEL, parent_window);
 
 	response = gtk_dialog_run (dialog);
-	gtk_object_destroy (GTK_OBJECT (dialog));
 		
 	if (response == GTK_RESPONSE_YES) {
 		launch_mime_capplet (file, dialog);	 
 	}
+	gtk_object_destroy (GTK_OBJECT (dialog));
 
 	g_free (unavailable_message);
 	g_free (file_name);
