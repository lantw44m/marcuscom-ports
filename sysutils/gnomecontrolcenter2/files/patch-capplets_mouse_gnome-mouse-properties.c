--- capplets/mouse/gnome-mouse-properties.c.orig	Thu Jul 14 16:27:10 2005
+++ capplets/mouse/gnome-mouse-properties.c	Thu Jul 14 16:27:36 2005
@@ -470,8 +470,9 @@ cursor_theme_changed (GConfClient *clien
 	GtkTreeModel    * smodel    = gtk_tree_view_get_model(view);
 	GtkTreeModel    * model     = gtk_tree_model_sort_get_model(GTK_TREE_MODEL_SORT(smodel));
 	gchar           * theme     = gconf_client_get_string (client, CURSOR_THEME_KEY, NULL);
+	gint size;
 	gtk_tree_model_get_iter_root(model, &iter);
-	gint              size      = gconf_client_get_int (client, CURSOR_SIZE_KEY, NULL);
+	size      = gconf_client_get_int (client, CURSOR_SIZE_KEY, NULL);
 	gtk_tree_model_get_iter_root(model, &iter);
 
 	do {
