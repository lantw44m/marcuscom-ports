--- rsvg-shapes.c.orig	Fri Sep  3 00:47:10 2004
+++ rsvg-shapes.c	Fri Sep  3 00:47:51 2004
@@ -646,9 +646,10 @@
 static void 
 rsvg_defs_drawable_group_pack (RsvgDefsDrawableGroup *self, RsvgDefsDrawable *child)
 {
+    	RsvgDefsDrawableGroup *z;
 	if (self == NULL)
 		return;
-	RsvgDefsDrawableGroup *z = (RsvgDefsDrawableGroup *)self;
+	z = (RsvgDefsDrawableGroup *)self;
 	g_ptr_array_add(z->children, child);
 }
 
@@ -704,11 +705,11 @@
 void
 rsvg_handle_path (RsvgHandle *ctx, const char * d, const char * id)
 {
+	RsvgDefsDrawablePath *path;
 	if (!ctx->in_defs)
 		rsvg_render_path (ctx, d);
 
 	   
-	RsvgDefsDrawablePath *path;
 	
 	path = g_new (RsvgDefsDrawablePath, 1);
 	path->d = g_strdup(d);
