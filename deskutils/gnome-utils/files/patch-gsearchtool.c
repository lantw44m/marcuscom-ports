--- gsearchtool/gsearchtool.c.orig	Fri Dec 17 10:31:38 2004
+++ gsearchtool/gsearchtool.c	Fri Dec 17 10:33:11 2004
@@ -2025,7 +2025,7 @@
 	
 	gtk_table_attach(GTK_TABLE(interface.table), label, 0, 1, 1, 2, GTK_FILL, 0, 0, 0);
 	
-	interface.look_in_folder_entry = gtk_file_chooser_button_new (_("Browse"));
+	interface.look_in_folder_entry = gtk_file_chooser_button_new (_("Browse"), GTK_FILE_CHOOSER_ACTION_OPEN);
 	gtk_file_chooser_set_action (GTK_FILE_CHOOSER (interface.look_in_folder_entry), GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
 	gtk_label_set_mnemonic_widget (GTK_LABEL(label), GTK_WIDGET (interface.look_in_folder_entry));		
 	gtk_table_attach (GTK_TABLE(interface.table), interface.look_in_folder_entry, 1, 2, 1, 2, GTK_EXPAND | GTK_FILL | GTK_SHRINK, 0, 0, 0);
