--- src/htmlgdkpainter.c.orig	Wed Dec  8 01:43:54 2004
+++ src/htmlgdkpainter.c	Wed Dec  8 01:44:12 2004
@@ -740,9 +740,10 @@
 item_gc (HTMLPainter *p, PangoItem *item, GdkDrawable *drawable, GdkGC *orig_gc, HTMLPangoProperties *properties, GdkGC **bg_gc)
 {
 	GdkGC *new_gc = NULL;
+	HTMLEngine *e;
 	html_pango_get_item_properties (item, properties);
 
-	HTMLEngine *e = GTK_HTML (p->widget)->engine;
+	e = GTK_HTML (p->widget)->engine;
 
 	*bg_gc = NULL;
 
