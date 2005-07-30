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
@@ -211,8 +210,9 @@
 scaled_font_extents (PycairoScaledFont *o)
 {
     cairo_font_extents_t e;
-    cairo_status_t status = cairo_scaled_font_extents (o->scaled_font, &e);
-    if (Pycairo_Check_Status (status))
+
+    cairo_scaled_font_extents (o->scaled_font, &e);
+    if (Pycairo_Check_Status (cairo_scaled_font_status(o->scaled_font)))
 	return NULL;
     return Py_BuildValue ("(ddddd)", e.ascent, e.descent, e.height, 
 			  e.max_x_advance, e.max_y_advance);
