--- gobject/gobjectmodule.c.orig	2008-08-08 00:58:57.000000000 -0400
+++ gobject/gobjectmodule.c	2008-08-08 01:00:31.000000000 -0400
@@ -1944,6 +1944,14 @@ pyg_threads_init (PyObject *unused, PyOb
     return Py_None;
 }
 
+int
+pygobject_enable_threads(void)
+{
+	if (!pyglib_enable_threads())
+		return -1;
+	return 0;
+}
+
 static PyObject *
 pyg_signal_accumulator_true_handled(PyObject *unused, PyObject *args)
 {
@@ -2639,7 +2647,7 @@ struct _PyGObject_Functions pygobject_ap
   pyg_flags_from_gtype,
 
   FALSE, /* threads_enabled */
-  pyglib_enable_threads,
+  pygobject_enable_threads,
   pygobject_gil_state_ensure,
   pygobject_gil_state_release,
   pyg_register_class_init,
