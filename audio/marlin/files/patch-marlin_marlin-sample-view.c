--- marlin/marlin-sample-view.c.orig	Mon Nov 17 12:40:57 2003
+++ marlin/marlin-sample-view.c	Mon Nov 17 12:41:18 2003
@@ -1615,8 +1615,8 @@
 #endif
 		if (red_dotted == NULL) {
 			GdkColor red = {0, 65535, 0, 0};
-			red_dotted = gdk_gc_new (widget->window);
 			GdkColormap *cmap = gdk_colormap_get_system ();
+			red_dotted = gdk_gc_new (widget->window);
 
 			gdk_gc_copy (red_dotted, widget->style->black_gc);
 
