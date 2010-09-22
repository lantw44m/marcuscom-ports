--- avahi-ui/avahi-ui.c.orig
+++ avahi-ui/avahi-ui.c
@@ -254,11 +254,13 @@ GtkWidget *aui_service_dialog_new_valist(
     const gchar *button_text;
     gint dr;
 
-    GtkWidget *w = GTK_WIDGET(g_object_new(
+    GtkWidget *w = (GtkWidget*)g_object_new(
                                       AUI_TYPE_SERVICE_DIALOG,
+#if !GTK_CHECK_VERSION (2,21,8)
                                       "has-separator", FALSE,
+#endif
                                       "title", title,
-                                      NULL));
+                                      NULL);
 
     if (parent)
         gtk_window_set_transient_for(GTK_WINDOW(w), parent);
@@ -985,7 +987,9 @@ static void domain_button_clicked(GtkButton *button G_GNUC_UNUSED, gpointer user
     p->domain_dialog = gtk_dialog_new();
     gtk_container_set_border_width(GTK_CONTAINER(p->domain_dialog), 5);
     gtk_window_set_title(GTK_WINDOW(p->domain_dialog), _("Change domain"));
+#if !GTK_CHECK_VERSION(2,21,8)
     gtk_dialog_set_has_separator(GTK_DIALOG(p->domain_dialog), FALSE);
+#endif
 
     vbox = gtk_vbox_new(FALSE, 8);
     gtk_container_set_border_width(GTK_CONTAINER(vbox), 8);
