--- /usr/obj/usr/ports/graphics/py-cairo/work/pycairo-0.5.1.1/cairo/pycairo-surface.c	Mon Jul 25 13:10:39 2005
+++ cairo/pycairo-surface.c	Sat Jul 30 17:17:21 2005
@@ -126,10 +126,10 @@
 static PyObject *
 surface_finish (PycairoSurface *o)
 {
-    cairo_status_t status = cairo_surface_finish (o->surface);
+    cairo_surface_finish (o->surface);
     Py_CLEAR(o->base);
 
-    if (Pycairo_Check_Status (status))
+    if (Pycairo_Check_Status (cairo_surface_status(o->surface)))
 	return NULL;
     Py_RETURN_NONE;
 }
