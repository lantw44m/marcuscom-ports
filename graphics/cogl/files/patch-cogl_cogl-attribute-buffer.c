--- cogl/cogl-attribute-buffer.c.orig	2013-10-31 12:42:44.000000000 +0100
+++ cogl/cogl-attribute-buffer.c	2013-10-31 12:47:49.000000000 +0100
@@ -37,7 +37,6 @@
 static void _cogl_attribute_buffer_free (CoglAttributeBuffer *array);
 
 COGL_BUFFER_DEFINE (AttributeBuffer, attribute_buffer);
-COGL_GTYPE_DEFINE_CLASS (AttributeBuffer, attribute_buffer);
 
 CoglAttributeBuffer *
 cogl_attribute_buffer_new_with_size (CoglContext *context,
