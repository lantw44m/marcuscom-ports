--- libgnomeprintui/gnome-print-unit-selector.c.orig	Sun Nov 30 13:06:40 2003
+++ libgnomeprintui/gnome-print-unit-selector.c	Sun Nov 30 13:07:16 2003
@@ -163,7 +163,7 @@
 	us->abbr = FALSE;
 	us->plural = TRUE;
 
-	us->combo = gtk_combo_box_new_with_model (
+	us->combo = gtk_combo_box_new (
 	    (GtkTreeModel *)gtk_list_store_new (N_COLUMNS, G_TYPE_STRING, G_TYPE_POINTER));
 	cell = gtk_cell_renderer_text_new ();
 	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (us->combo), cell, TRUE);
