--- src/vtegl.c.orig	Wed May  7 02:30:06 2003
+++ src/vtegl.c	Wed May  7 02:30:15 2003
@@ -312,8 +312,7 @@
 _vte_gl_clear(struct _vte_draw *draw,
 		 gint x, gint y, gint width, gint height)
 {
-	struct _vte_gl_data *data;
-	data = (struct _vte_gl_data*) draw->impl_data;
+	struct _vte_gl_data *data = (struct _vte_gl_data*) draw->impl_data;
 	long xstop, ystop, i, j;
 	int pixmapw, pixmaph, w, h;
 
