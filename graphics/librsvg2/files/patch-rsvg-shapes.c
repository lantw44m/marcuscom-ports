--- rsvg-shapes.c.orig	Tue Jul 19 23:47:27 2005
+++ rsvg-shapes.c	Fri Sep  9 12:34:17 2005
@@ -145,12 +145,13 @@
 					 int dominate)
 {
 	RsvgNodePoly * poly = (RsvgNodePoly *)self;
+	gsize i;
+	GString * d;
 	/* represent as a "moveto, lineto*, close" path */  
 	if (poly->pointlist_len < 2)
 		return;
 
-	gsize i;
-	GString * d = g_string_new ("");
+	d = g_string_new ("");
 	g_string_append_printf (d, "M %f %f ", poly->pointlist[0], poly->pointlist[1] );
 	
 	for (i = 2; i < poly->pointlist_len; i += 2)
