--- capplets/file-types/mime-edit-dialog.c.orig	Sat Jan 24 02:41:49 2004
+++ capplets/file-types/mime-edit-dialog.c	Sat Jan 24 02:42:26 2004
@@ -406,11 +406,8 @@
 		     char const *file_name) 
 {
 	GObject *dialog = g_object_new (mime_edit_dialog_get_type (),
-		"model", model,	/* must be before is-add */
+		"model", model, "is-add", TRUE, /* model must be before is-add */
 		NULL);
-	g_object_set (dialog,
-		      "is-add", TRUE,
-		      NULL);
 	if (parent != NULL)
 		gtk_window_set_transient_for (
 			GTK_WINDOW (MIME_EDIT_DIALOG (dialog)->p->dialog_win),
