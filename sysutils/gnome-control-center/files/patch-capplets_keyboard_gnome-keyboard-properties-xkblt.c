--- capplets/keyboard/gnome-keyboard-properties-xkblt.c.orig	Thu Jan 13 02:49:37 2005
+++ capplets/keyboard/gnome-keyboard-properties-xkblt.c	Thu Jan 13 02:51:22 2005
@@ -105,11 +105,13 @@
 
   if (value->type == GCONF_VALUE_INT)
     {
-      defaultGroup = gconf_value_get_int (value);
-      GtkWidget* treeView = WID ("xkb_layouts_selected");
-      GtkTreeModel *model = GTK_TREE_MODEL (gtk_tree_view_get_model (GTK_TREE_VIEW (treeView)));
+      GtkWidget* treeView;
+      GtkTreeModel *model;
       GtkTreeIter iter;
       int counter = 0;
+      defaultGroup = gconf_value_get_int (value);
+      treeView = WID ("xkb_layouts_selected");
+      model = GTK_TREE_MODEL (gtk_tree_view_get_model (GTK_TREE_VIEW (treeView)));
       if (gtk_tree_model_get_iter_first (model, &iter))
         {
           do
