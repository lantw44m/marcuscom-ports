--- rsvg-filter.c.orig	Wed Jun  9 01:24:25 2004
+++ rsvg-filter.c	Wed Jun  9 01:24:32 2004
@@ -484,9 +484,9 @@
 rsvg_filter_store_output(GString * name, RsvgFilterPrimitiveOutput result,
 						  RsvgFilterContext * ctx)
 {
+	RsvgFilterPrimitiveOutput * store;
 	g_object_unref (G_OBJECT (ctx->lastresult.result));
 	
-	RsvgFilterPrimitiveOutput * store;
 
 	store = g_new(RsvgFilterPrimitiveOutput, 1);
 	*store = result;
