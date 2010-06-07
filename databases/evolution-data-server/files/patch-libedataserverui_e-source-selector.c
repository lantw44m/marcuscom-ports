Very very hacky patch. Seems GSEAL screws up somehow. 
Review after next gtk (2.12.2) update.

--- libedataserverui/e-source-selector.c.orig	2010-06-07 13:37:26.000000000 +0200
+++ libedataserverui/e-source-selector.c	2010-06-07 14:06:35.000000000 +0200
@@ -965,10 +965,12 @@
 	pos = GTK_TREE_VIEW_DROP_INTO_OR_BEFORE;
 	gtk_tree_view_set_drag_dest_row (tree_view, path, pos);
 
-	if (gdk_drag_context_get_actions (context) & GDK_ACTION_MOVE)
+/*	if (gdk_drag_context_get_actions (context) & GDK_ACTION_MOVE) */
+	if (context->_g_sealed__action & GDK_ACTION_MOVE)
 		action = GDK_ACTION_MOVE;
 	else
-		action = gdk_drag_context_get_suggested_action (context);
+		action = context->_g_sealed__suggested_action;
+/*		action = gdk_drag_context_get_suggested_action (context);*/
 
 exit:
 	if (path != NULL)
@@ -1034,7 +1036,8 @@
 
 	tree_view = GTK_TREE_VIEW (widget);
 	model = gtk_tree_view_get_model (tree_view);
-	delete = (gdk_drag_context_get_selected_action (context) == GDK_ACTION_MOVE);
+/*	delete = (gdk_drag_context_get_selected_action (context) == GDK_ACTION_MOVE); */
+	delete = (context->_g_sealed__action == GDK_ACTION_MOVE);
 
 	if (!gtk_tree_view_get_dest_row_at_pos (tree_view, x, y, &path, NULL))
 		goto exit;
@@ -1049,7 +1052,8 @@
 
 	g_signal_emit (
 		widget, signals[DATA_DROPPED], 0, selection_data,
-		object, gdk_drag_context_get_selected_action (context),
+/*		object, gdk_drag_context_get_selected_action (context), */
+		object, context->_g_sealed__action,
                 info, &success);
 
 exit:
