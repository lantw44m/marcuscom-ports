--- src/vncdisplay.c.orig	2010-07-12 16:30:50.000000000 +0200
+++ src/vncdisplay.c	2010-07-12 16:51:46.000000000 +0200
@@ -382,12 +382,12 @@
 
 	if (priv->pixmap != NULL) {
 		gdk_gc_set_clip_region(priv->gc, copy);
-		gdk_draw_drawable(widget->window, priv->gc, priv->pixmap,
+		gdk_draw_drawable(gtk_widget_get_window(widget), priv->gc, priv->pixmap,
 				  x, y, x + mx, y + my, w, h);
 	}
 
 	gdk_gc_set_clip_region(priv->gc, clear);
-	gdk_draw_rectangle(widget->window, priv->gc, TRUE,
+	gdk_draw_rectangle(gtk_widget_get_window(widget), priv->gc, TRUE,
 			   expose->area.x, expose->area.y,
 			   expose->area.width, expose->area.height);
 
