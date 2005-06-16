--- plugins/print-message/print-message.c.orig	Wed Jun 15 19:36:52 2005
+++ plugins/print-message/print-message.c	Wed Jun 15 19:37:09 2005
@@ -74,13 +74,14 @@ org_gnome_print_message (EPlugin *ep, EM
 
        	EMsgComposer *composer = (EMsgComposer *)t->target.widget;
 	struct _print_data *data;
+	GtkDialog *dialog;
 	
 	data = g_malloc0(sizeof(*data));
 	data->config = e_print_load_config ();
 	data->preview = 0;
 	
 	data->msg = e_msg_composer_get_message (composer, 1);
-	GtkDialog *dialog = (GtkDialog *)e_print_get_dialog_with_config (_("Print Message"), GNOME_PRINT_DIALOG_COPIES, data->config);
+	dialog = (GtkDialog *)e_print_get_dialog_with_config (_("Print Message"), GNOME_PRINT_DIALOG_COPIES, data->config);
 	 gtk_dialog_set_default_response(dialog, GNOME_PRINT_DIALOG_RESPONSE_PRINT);
 	e_dialog_set_transient_for ((GtkWindow *) dialog, (GtkWidget *) composer);
 	g_signal_connect(dialog, "response", G_CALLBACK(print_response), data);
