--- gui/contract/editor/e-contact-editor.c.orig	Tue Aug 23 14:46:51 2005
+++ gui/contract/editor/e-contact-editor.c	Tue Aug 23 14:47:29 2005
@@ -581,10 +581,12 @@ sensitize_ok (EContactEditor *ce)
 	gboolean   allow_save;
 	GtkWidget *entry_fullname;
 	GtkWidget *entry_file_as;
+	const char *name_entry_string;
+	const char *file_as_entry_string;
 	entry_fullname = glade_xml_get_widget (ce->gui, "entry-fullname" );
 	entry_file_as = glade_xml_get_widget (ce->gui, "entry-file-as");
-	const char *name_entry_string = gtk_entry_get_text (GTK_ENTRY (entry_fullname));
-	const char *file_as_entry_string = gtk_entry_get_text (GTK_ENTRY (entry_file_as));
+	name_entry_string = gtk_entry_get_text (GTK_ENTRY (entry_fullname));
+	file_as_entry_string = gtk_entry_get_text (GTK_ENTRY (entry_file_as));
 
 	allow_save = ce->target_editable && ce->changed ? TRUE : FALSE;
 
