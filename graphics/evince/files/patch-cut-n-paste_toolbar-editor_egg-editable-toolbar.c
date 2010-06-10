--- cut-n-paste/toolbar-editor/egg-editable-toolbar.c.orig	2010-06-10 17:54:30.000000000 +0200
+++ cut-n-paste/toolbar-editor/egg-editable-toolbar.c	2010-06-10 17:55:15.000000000 +0200
@@ -695,12 +695,12 @@ toolbar_drag_data_received_cb (GtkToolba
           gint tpos = get_toolbar_position (etoolbar, GTK_WIDGET (toolbar));
           egg_toolbars_model_add_item (etoolbar->priv->model, tpos, ipos, name);
           gtk_drag_finish (context, TRUE,
-			   gdk_drag_context_get_action (context) == GDK_ACTION_MOVE, time);
+			   gdk_drag_context_get_selected_action (context) == GDK_ACTION_MOVE, time);
         }
       else
         {
           gtk_drag_finish (context, FALSE,
-			   gdk_drag_context_get_action (context) == GDK_ACTION_MOVE, time);
+			   gdk_drag_context_get_selected_action (context) == GDK_ACTION_MOVE, time);
         }
     }
 
