--- src/dialogs/dialog-sheet-order.c.orig	Mon Sep 15 15:15:28 2003
+++ src/dialogs/dialog-sheet-order.c	Mon Sep 15 15:16:20 2003
@@ -111,13 +111,14 @@
 /* 		(GTK_TREE_MODEL (model), iter); */
 
 	/* in gtk 2.0 we need: */
+	gint loc;
 	GtkTreePath *treepath = gtk_tree_model_get_path 
 		(GTK_TREE_MODEL (model), iter);
 	gchar* path = gtk_tree_path_to_string (treepath);
 	gtk_tree_path_free (treepath);
 	/* end of gtk 2.0 code */
 
-	gint loc = atoi(path);
+	loc = atoi(path);
 	
 	g_free (path);
 
