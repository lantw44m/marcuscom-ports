--- libgnomeprintui/gnome-font-dialog.c.orig	Sun Nov 30 13:04:55 2003
+++ libgnomeprintui/gnome-font-dialog.c	Sun Nov 30 13:06:28 2003
@@ -258,7 +258,7 @@
 	fontsel->sizebox = hb;
 
 	model = (GtkTreeModel *) gtk_list_store_new (1, G_TYPE_STRING);
-	c = gtk_combo_box_entry_new_with_model (model, 0);
+	c = gtk_combo_box_entry_new (model, 0);
 	gtk_widget_set_size_request (c, 64, -1);
 	gtk_widget_show (c);
 	g_signal_connect (G_OBJECT (c), "changed",
