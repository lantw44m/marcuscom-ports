--- rsvg-shapes.c.orig	Thu Aug 25 22:32:03 2005
+++ rsvg-shapes.c	Thu Aug 25 22:32:13 2005
@@ -145,12 +145,12 @@ _rsvg_node_poly_draw(RsvgNode * self, Rs
 					 int dominate)
 {
 	RsvgNodePoly * poly = (RsvgNodePoly *)self;
+	gsize i;
+	GString * d = g_string_new ("");
 	/* represent as a "moveto, lineto*, close" path */  
 	if (poly->pointlist_len < 2)
 		return;
 
-	gsize i;
-	GString * d = g_string_new ("");
 	g_string_append_printf (d, "M %f %f ", poly->pointlist[0], poly->pointlist[1] );
 	
 	for (i = 2; i < poly->pointlist_len; i += 2)
