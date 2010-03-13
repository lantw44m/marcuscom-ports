--- clutter-gtk/gtk-clutter-embed.c.orig	2009-06-27 16:21:06.000000000 +0200
+++ clutter-gtk/gtk-clutter-embed.c	2010-03-13 20:56:41.000000000 +0100
@@ -131,7 +131,7 @@ gtk_clutter_embed_show (GtkWidget *widge
 {
   GtkClutterEmbedPrivate *priv = GTK_CLUTTER_EMBED (widget)->priv;
 
-  if (GTK_WIDGET_REALIZED (widget))
+  if (gtk_widget_get_realized (widget))
     clutter_actor_show (priv->stage);
 
   GTK_WIDGET_CLASS (gtk_clutter_embed_parent_class)->show (widget);
@@ -222,7 +222,7 @@ gtk_clutter_embed_realize (GtkWidget *wi
 
   clutter_actor_realize (priv->stage);
 
-  if (GTK_WIDGET_VISIBLE (widget))
+  if (gtk_widget_get_visible (widget))
     clutter_actor_show (priv->stage);
 
   gtk_clutter_embed_send_configure (GTK_CLUTTER_EMBED (widget));
@@ -246,7 +246,7 @@ gtk_clutter_embed_size_allocate (GtkWidg
 
   widget->allocation = *allocation;
 
-  if (GTK_WIDGET_REALIZED (widget))
+  if (gtk_widget_get_realized (widget))
     {
       gdk_window_move_resize (widget->window,
                               allocation->x, allocation->y,
