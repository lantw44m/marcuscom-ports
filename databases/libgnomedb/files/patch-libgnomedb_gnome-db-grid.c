--- libgnomedb/gnome-db-grid.c.orig	Tue Jun  7 16:37:54 2005
+++ libgnomedb/gnome-db-grid.c	Tue Jun  7 16:38:13 2005
@@ -1916,8 +1916,9 @@ tree_view_selection_changed_cb (GtkTreeS
 	}
 	else {
 		/* render all the parameters invalid */
+		GSList *list;
 		grid->priv->internal_params_change = TRUE;
-		GSList *list = grid->priv->data_set->parameters;
+		list = grid->priv->data_set->parameters;
 		while (list) {
 			GnomeDbParameter *tmp;
 			g_object_get (G_OBJECT (list->data), "simple_bind", &tmp, NULL);
