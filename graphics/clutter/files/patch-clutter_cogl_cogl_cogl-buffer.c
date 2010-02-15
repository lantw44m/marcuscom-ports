--- clutter/cogl/cogl/cogl-buffer.c.orig	2010-02-15 10:33:30.000000000 +0100
+++ clutter/cogl/cogl/cogl-buffer.c	2010-02-15 10:42:26.000000000 +0100
@@ -272,9 +272,9 @@ cogl_buffer_unmap_EXP (CoglHandle handle
 
 gboolean
 cogl_buffer_set_data_EXP (CoglHandle    handle,
-                          guint         offset,
+                          gsize         offset,
                           const guchar *data,
-                          guint         size)
+                          gsize         size)
 {
   CoglBuffer *buffer;
 
