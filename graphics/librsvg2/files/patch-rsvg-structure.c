--- rsvg-structure.c.orig	Thu Aug 25 22:32:30 2005
+++ rsvg-structure.c	Thu Aug 25 22:32:38 2005
@@ -360,8 +360,8 @@ rsvg_node_use_set_atts (RsvgNode * self,
 {
 	const char *value = NULL, *klazz = NULL, *id = NULL;
 	double font_size;	
-	font_size = rsvg_state_current_font_size(ctx);
 	RsvgNodeUse * use;
+	font_size = rsvg_state_current_font_size(ctx);
 
 	use = (RsvgNodeUse *)self;
 	if (rsvg_property_bag_size(atts))
