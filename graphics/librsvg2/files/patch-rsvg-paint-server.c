--- rsvg-paint-server.c.orig	Fri Sep  3 00:46:30 2004
+++ rsvg-paint-server.c	Fri Sep  3 00:46:44 2004
@@ -488,13 +488,13 @@
 	double affine[6];
 	double caffine[6];
 	int i, j;
+	gdouble minx, miny, maxx, maxy, xcoord, ycoord, xoffset, yoffset;
+	GdkPixbuf *save, *render;
 
 	if (ctx->ctx == NULL)
 		return;
 
-	gdouble minx, miny, maxx, maxy, xcoord, ycoord, xoffset, yoffset;
 	
-	GdkPixbuf *save, *render;
 
 	if (pattern->obj_bbox) {
 		affine[0] = ctx->x1 - ctx->x0;
