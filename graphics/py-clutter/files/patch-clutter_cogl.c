--- clutter/cogl.c.orig	2010-08-26 14:30:51.000000000 -0400
+++ clutter/cogl.c	2010-08-26 14:31:06.000000000 -0400
@@ -3799,7 +3799,6 @@ pycogl_add_constants(PyObject *module, c
 #ifdef VERSION
     PyModule_AddStringConstant(module, "__version__", VERSION);
 #endif
-  pyg_flags_add(module, "DebugFlags", strip_prefix, COGL_TYPE_DEBUG_FLAGS);
   pyg_flags_add(module, "BufferBit", strip_prefix, COGL_TYPE_BUFFER_BIT);
   pyg_enum_add(module, "ShaderType", strip_prefix, COGL_TYPE_SHADER_TYPE);
   pyg_enum_add(module, "PixelFormat", strip_prefix, COGL_TYPE_PIXEL_FORMAT);
