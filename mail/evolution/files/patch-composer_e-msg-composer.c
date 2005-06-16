--- composer/e-msg-composer.c.orig	Wed Jun 15 18:14:55 2005
+++ composer/e-msg-composer.c	Wed Jun 15 18:15:04 2005
@@ -3367,7 +3367,7 @@ create_composer (int visible_mask)
 	GList *icon_list;
 	BonoboControlFrame *control_frame;
 	GtkWidget *html_widget = NULL;
-	gpointer servant;;
+	gpointer servant;
 	BonoboObject *impl;	
 	
 	composer = g_object_new (E_TYPE_MSG_COMPOSER, "win_name", _("Compose a message"), NULL);
