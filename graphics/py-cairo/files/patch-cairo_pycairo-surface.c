--- cairo/pycairo-surface.c	2006/05/28 02:03:07	1.73
+++ cairo/pycairo-surface.c	2006/06/25 05:54:34	1.76
@@ -194,6 +194,12 @@
 }
 
 static PyObject *
+surface_get_content (PycairoSurface *o)
+{
+    return PyInt_FromLong (cairo_surface_get_content (o->surface));
+}
+
+static PyObject *
 surface_get_device_offset (PycairoSurface *o)
 {
     double x_offset, y_offset;
@@ -242,6 +248,18 @@
     Py_RETURN_NONE;
 }
 
+static PyObject *
+surface_set_fallback_resolution (PycairoSurface *o, PyObject *args)
+{
+    double x_ppi, y_ppi;
+
+    if (!PyArg_ParseTuple(args, "dd:Surface.set_fallback_resolution",
+			  &x_ppi, &y_ppi))
+	return NULL;
+    cairo_surface_set_fallback_resolution (o->surface, x_ppi, y_ppi);
+    Py_RETURN_NONE;
+}
+
 #ifdef CAIRO_HAS_PNG_FUNCTIONS
 /* METH_O */
 static PyObject *
@@ -285,12 +303,15 @@
     {"create_similar", (PyCFunction)surface_create_similar,    METH_VARARGS },
     {"finish",         (PyCFunction)surface_finish,            METH_NOARGS },
     {"flush",          (PyCFunction)surface_flush,             METH_NOARGS },
+    {"get_content",    (PyCFunction)surface_get_content,       METH_NOARGS },
     {"get_device_offset",(PyCFunction)surface_get_device_offset,
                                                                 METH_NOARGS },
     {"get_font_options",(PyCFunction)surface_get_font_options, METH_NOARGS },
     {"mark_dirty",     (PyCFunction)surface_mark_dirty,        METH_KEYWORDS },
     {"set_device_offset",(PyCFunction)surface_set_device_offset,
                                                                 METH_VARARGS },
+    {"set_fallback_resolution",(PyCFunction)surface_set_fallback_resolution,
+                                                                METH_VARARGS },
 #ifdef CAIRO_HAS_PNG_FUNCTIONS
     {"write_to_png",   (PyCFunction)surface_write_to_png,      METH_O },
 #endif
@@ -459,7 +480,8 @@
 	    stride = (width + 1) / 8;
 	    break;
 	default:
-	    ASSERT_NOT_REACHED;
+	    PyErr_SetString(CairoError, "Unknown format");
+	    return NULL;
 	}
     }
     if (height * stride > buffer_len) {
@@ -474,15 +496,7 @@
 
 #ifdef CAIRO_HAS_PNG_FUNCTIONS
 static cairo_status_t
-_read_func1 (void *closure, unsigned char *data, unsigned int length)
-{
-    if (fread (data, 1, (size_t) length, (FILE *)closure) != length)
-	return CAIRO_STATUS_READ_ERROR;
-    return CAIRO_STATUS_SUCCESS;
-}
-
-static cairo_status_t
-_read_func2 (void *closure, unsigned char *data, unsigned int length)
+_read_func (void *closure, unsigned char *data, unsigned int length)
 {
     char *str;
     PyObject *pystr = PyObject_CallMethod ((PyObject *)closure, "read", "(i)",
@@ -502,58 +516,50 @@
 static PyObject *
 image_surface_create_from_png (PyTypeObject *type, PyObject *file)
 {
-    FILE *fp = NULL;
-    cairo_surface_t *surface;
-    unsigned int mode = 0;
-
     if (PyObject_TypeCheck (file, &PyBaseString_Type)) {
-	fp = fopen (PyString_AsString(file), "rb");
-	if (fp == NULL) {
-	    PyErr_SetString(PyExc_IOError, "unable to open file for reading");
-	    return NULL;
-	}
-	mode = 1;
-    } else if (PyObject_TypeCheck (file, &PyFile_Type)) {
-	fp = PyFile_AsFile(file);
-	mode = 1;
-    } else {
-	PyObject* reader = PyObject_GetAttrString (file, "read");
-	if (reader) {
-	    if (PyCallable_Check (reader))
-		mode = 2;
-	    Py_DECREF(reader);
-	}
+	return PycairoSurface_FromSurface (
+            cairo_image_surface_create_from_png (PyString_AsString(file)),
+            NULL);
     }
-    if (mode == 1) {
-	surface = cairo_image_surface_create_from_png_stream (_read_func1, fp);
-    } else if (mode == 2) {
-	surface = cairo_image_surface_create_from_png_stream (_read_func2,
-							      file);
-    } else {
+
+    /* file or file-like object argument */
+    PyObject* reader = PyObject_GetAttrString (file, "read");
+    if (reader == NULL || !PyCallable_Check (reader)) {
+	Py_XDECREF(reader);
 	PyErr_SetString(PyExc_TypeError,
-			"ImageSurface.create_from_png takes one argument "
-			"which must be a filename (str), file object, or an "
-			"object that has a \"read\" method (like StringIO)");
+"ImageSurface.create_from_png argument must be a filename (str), file object, "
+"or an object that has a \"read\" method (like StringIO)");
 	return NULL;
     }
+    Py_DECREF(reader);
 
-    if (PyObject_TypeCheck (file, &PyBaseString_Type))
-	fclose (fp);
-
-    return PycairoSurface_FromSurface (surface, NULL);
+    return PycairoSurface_FromSurface (
+        cairo_image_surface_create_from_png_stream (_read_func, file), NULL);
 }
 #endif /* CAIRO_HAS_PNG_FUNCTIONS */
 
 static PyObject *
+image_surface_get_format (PycairoImageSurface *o)
+{
+    return PyInt_FromLong (cairo_image_surface_get_format (o->surface));
+}
+
+static PyObject *
 image_surface_get_height (PycairoImageSurface *o)
 {
-    return Py_BuildValue("i", cairo_image_surface_get_height (o->surface));
+    return PyInt_FromLong (cairo_image_surface_get_height (o->surface));
 }
 
 static PyObject *
 image_surface_get_width (PycairoImageSurface *o)
 {
-    return Py_BuildValue("i", cairo_image_surface_get_width (o->surface));
+    return PyInt_FromLong (cairo_image_surface_get_width (o->surface));
+}
+
+static PyObject *
+image_surface_get_stride (PycairoImageSurface *o)
+{
+    return PyInt_FromLong (cairo_image_surface_get_stride (o->surface));
 }
 
 #ifdef HAVE_GETDATA
@@ -632,8 +638,10 @@
     {"create_from_png", (PyCFunction)image_surface_create_from_png,
                                                    METH_O | METH_CLASS },
 #endif
+    {"get_format",    (PyCFunction)image_surface_get_format,     METH_NOARGS},
     {"get_height",    (PyCFunction)image_surface_get_height,     METH_NOARGS},
     {"get_width",     (PyCFunction)image_surface_get_width,      METH_NOARGS},
+    {"get_stride",    (PyCFunction)image_surface_get_stride,     METH_NOARGS},
 #ifdef HAVE_GETDATA
     {"to_rgba",       (PyCFunction)image_surface_to_rgba,        METH_NOARGS},
 #endif
@@ -707,34 +715,22 @@
                   cairo_pdf_surface_create (PyString_AsString(file),
                                      width_in_points, height_in_points),
 	       NULL);
-
-    } else {  /* file or file-like object argument */
-	PyObject* writer = PyObject_GetAttrString (file, "write");
-	if (writer == NULL || !PyCallable_Check (writer)) {
-	    Py_XDECREF(writer);
-	    PyErr_SetString(PyExc_TypeError,
+    }
+    /* file or file-like object argument */
+    PyObject* writer = PyObject_GetAttrString (file, "write");
+    if (writer == NULL || !PyCallable_Check (writer)) {
+	Py_XDECREF(writer);
+	PyErr_SetString(PyExc_TypeError,
 "PDFSurface argument 1 must be a filename (str), file object, or an object "
 "that has a \"write\" method (like StringIO)");
-	    return NULL;
-	}
-	Py_DECREF(writer);
-
-	return PycairoSurface_FromSurface (
-	           cairo_pdf_surface_create_for_stream (_write_func,
-		       file, width_in_points, height_in_points),
-	       file);
+	return NULL;
     }
-}
-
-static PyObject *
-pdf_surface_set_dpi (PycairoPDFSurface *o, PyObject *args)
-{
-    double x_dpi, y_dpi;
+    Py_DECREF(writer);
 
-    if (!PyArg_ParseTuple(args, "dd:PDFSurface.set_dpi", &x_dpi, &y_dpi))
-	return NULL;
-    cairo_pdf_surface_set_dpi (o->surface, x_dpi, y_dpi);
-    Py_RETURN_NONE;
+    return PycairoSurface_FromSurface (
+	       cairo_pdf_surface_create_for_stream (_write_func, file,
+		   width_in_points, height_in_points),
+	   file);
 }
 
 static PyObject *
@@ -751,7 +747,6 @@
 }
 
 static PyMethodDef pdf_surface_methods[] = {
-    {"set_dpi",  (PyCFunction)pdf_surface_set_dpi,     METH_VARARGS },
     {"set_size", (PyCFunction)pdf_surface_set_size,    METH_VARARGS },
     {NULL, NULL, 0, NULL},
 };
@@ -824,22 +819,22 @@
                                      width_in_points, height_in_points),
 	       NULL);
 
-    } else {  /* file or file-like object argument */
-	PyObject* writer = PyObject_GetAttrString (file, "write");
-	if (writer == NULL || !PyCallable_Check (writer)) {
-	    Py_XDECREF(writer);
-	    PyErr_SetString(PyExc_TypeError,
+    }
+    /* else: file or file-like object argument */
+    PyObject* writer = PyObject_GetAttrString (file, "write");
+    if (writer == NULL || !PyCallable_Check (writer)) {
+	Py_XDECREF(writer);
+	PyErr_SetString(PyExc_TypeError,
 "PSSurface argument 1 must be a filename (str), file object, or an object "
 "that has a \"write\" method (like StringIO)");
-	    return NULL;
-	}
-	Py_DECREF(writer);
+	return NULL;
+    }
+    Py_DECREF(writer);
 
-	return PycairoSurface_FromSurface (
-	           cairo_ps_surface_create_for_stream (_write_func,
-		       file, width_in_points, height_in_points),
+    return PycairoSurface_FromSurface (
+	       cairo_ps_surface_create_for_stream (_write_func, file,
+                   width_in_points, height_in_points),
 	       file);
-    }
 }
 
 static PyObject *
@@ -875,17 +870,6 @@
 }
 
 static PyObject *
-ps_surface_set_dpi (PycairoPSSurface *o, PyObject *args)
-{
-    double x_dpi, y_dpi;
-
-    if (!PyArg_ParseTuple(args, "dd:PSSurface.set_dpi", &x_dpi, &y_dpi))
-	return NULL;
-    cairo_ps_surface_set_dpi (o->surface, x_dpi, y_dpi);
-    Py_RETURN_NONE;
-}
-
-static PyObject *
 ps_surface_set_size (PycairoPSSurface *o, PyObject *args)
 {
     double width_in_points, height_in_points;
@@ -902,7 +886,6 @@
                    (PyCFunction)ps_surface_dsc_begin_page_setup, METH_NOARGS },
     {"dsc_begin_setup", (PyCFunction)ps_surface_dsc_begin_setup, METH_NOARGS },
     {"dsc_comment", (PyCFunction)ps_surface_dsc_comment,        METH_VARARGS },
-    {"set_dpi",  (PyCFunction)ps_surface_set_dpi,               METH_VARARGS },
     {"set_size", (PyCFunction)ps_surface_set_size,              METH_VARARGS },
     {NULL, NULL, 0, NULL},
 };
@@ -974,34 +957,22 @@
                   cairo_svg_surface_create (PyString_AsString(file),
                                      width_in_points, height_in_points),
 	       NULL);
-
-    } else {  /* file or file-like object argument */
-	PyObject* writer = PyObject_GetAttrString (file, "write");
-	if (writer == NULL || !PyCallable_Check (writer)) {
-	    Py_XDECREF(writer);
-	    PyErr_SetString(PyExc_TypeError,
+    }
+    /* else: file or file-like object argument */
+    PyObject* writer = PyObject_GetAttrString (file, "write");
+    if (writer == NULL || !PyCallable_Check (writer)) {
+	Py_XDECREF(writer);
+	PyErr_SetString(PyExc_TypeError,
 "SVGSurface argument 1 must be a filename (str), file object, or an object "
 "that has a \"write\" method (like StringIO)");
-	    return NULL;
-	}
-	Py_DECREF(writer);
-
-	return PycairoSurface_FromSurface (
-	           cairo_svg_surface_create_for_stream (_write_func,
-		       file, width_in_points, height_in_points),
-	       file);
+	return NULL;
     }
-}
+    Py_DECREF(writer);
 
-static PyObject *
-svg_surface_set_dpi (PycairoSVGSurface *o, PyObject *args)
-{
-    double x_dpi, y_dpi;
-
-    if (!PyArg_ParseTuple(args, "dd:SVGSurface.set_dpi", &x_dpi, &y_dpi))
-	return NULL;
-    cairo_svg_surface_set_dpi (o->surface, x_dpi, y_dpi);
-    Py_RETURN_NONE;
+    return PycairoSurface_FromSurface (
+	       cairo_svg_surface_create_for_stream (_write_func, file,
+	           width_in_points, height_in_points),
+	       file);
 }
 
 static PyMethodDef svg_surface_methods[] = {
@@ -1010,7 +981,6 @@
      * cairo_svg_get_versions
      * cairo_svg_version_to_string
      */
-    {"set_dpi", (PyCFunction)svg_surface_set_dpi,    METH_VARARGS },
     {NULL, NULL, 0, NULL},
 };
 
@@ -1142,7 +1112,7 @@
 static PyObject *
 xlib_surface_get_depth (PycairoXlibSurface *o)
 {
-    return Py_BuildValue("i", cairo_xlib_surface_get_depth (o->surface));
+    return PyInt_FromLong (cairo_xlib_surface_get_depth (o->surface));
 }
 
 static PyMethodDef xlib_surface_methods[] = {
