--- gnome-screenshot/screenshot-dialog.c.orig	Fri Dec 17 10:34:55 2004
+++ gnome-screenshot/screenshot-dialog.c	Fri Dec 17 10:35:38 2004
@@ -210,7 +210,7 @@
   dialog->filename_entry = glade_xml_get_widget (dialog->xml, "filename_entry");
   file_chooser_frame = glade_xml_get_widget (dialog->xml, "file_chooser_frame");
 
-  dialog->save_widget = gtk_file_chooser_button_new ("Select a directory");
+  dialog->save_widget = gtk_file_chooser_button_new ("Select a directory",GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
   gtk_file_chooser_set_local_only (GTK_FILE_CHOOSER (dialog->save_widget), FALSE);
   gtk_file_chooser_set_action (GTK_FILE_CHOOSER (dialog->save_widget),
 			       GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
