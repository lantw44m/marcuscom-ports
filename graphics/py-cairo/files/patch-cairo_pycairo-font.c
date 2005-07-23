--- cairo/pycairo-font.c.orig	Fri Jul 22 21:34:39 2005
+++ cairo/pycairo-font.c	Fri Jul 22 21:35:38 2005
@@ -183,6 +183,7 @@
 {
     PycairoFontFace *ff;
     PycairoMatrix *mx1, *mx2;
+    PyObject *o;
 
     if (!PyArg_ParseTuple(args, "O!O!O!:ScaledFont.__init__",
 			  &PycairoFontFace_Type, &ff,
@@ -190,7 +191,7 @@
 			  &PycairoMatrix_Type, &mx2))
 	return NULL;
 
-    PyObject *o = type->tp_alloc(type, 0);
+    o = type->tp_alloc(type, 0);
     if (o) {
 	cairo_scaled_font_t *scaled_font = cairo_scaled_font_create 
 	    (ff->font_face, &mx1->matrix, &mx2->matrix);
