--- pdf2djvu.cc.orig	2009-09-28 11:26:02.000000000 +0200
+++ pdf2djvu.cc	2009-09-28 11:37:12.000000000 +0200
@@ -277,6 +277,8 @@ public:
     return !config.no_render;
   }
 
+#if POPPLER_VERSION < 1101
+
   void drawImageMask(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream, int width, int height, 
     pdf::Bool invert, pdf::Bool inline_image)
   {
@@ -310,6 +312,48 @@ public:
       color_map, mask_stream, mask_width, mask_height, mask_color_map);
   }
 
+#else
+ 
+  void drawImageMask(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream, int width, int height,
+    pdf::Bool invert, pdf::Bool interpolate, pdf::Bool inline_image)
+  {
+    return;
+  }
+ 
+  void drawImage(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream, int width, int height,
+    pdf::gfx::ImageColorMap *color_map, pdf::Bool interpolate, int *mask_colors, pdf::Bool inline_image)
+  {
+    if (is_foreground_color_map(color_map) || config.no_render)
+      return;
+    Renderer::drawImage(state, object, stream, width, height, color_map, interpolate, mask_colors, inline_image);
+  }
+ 
+  void drawMaskedImage(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream, int width, int height,
+    pdf::gfx::ImageColorMap *color_map, pdf::Bool interpolate,
+    pdf::Stream *mask_stream, int mask_width, int mask_height, pdf::Bool mask_invert, pdf::Bool mask_interpolate)
+  {
+    if (is_foreground_color_map(color_map) || config.no_render)
+      return;
+    Renderer::drawMaskedImage(state, object, stream, width, height,
+      color_map, interpolate,
+      mask_stream, mask_width, mask_height, mask_invert, mask_interpolate);
+ 
+  }
+ 
+  void drawSoftMaskedImage(pdf::gfx::State *state, pdf::Object *object, pdf::Stream *stream,
+    int width, int height, pdf::gfx::ImageColorMap *color_map, pdf::Bool interpolate,
+    pdf::Stream *mask_stream, int mask_width, int mask_height,
+    pdf::gfx::ImageColorMap *mask_color_map, pdf::Bool mask_interpolate)
+  {
+    if (is_foreground_color_map(color_map) || config.no_render)
+      return;
+    Renderer::drawSoftMaskedImage(state, object, stream, width, height,
+      color_map, interpolate,
+      mask_stream, mask_width, mask_height, mask_color_map, mask_interpolate);
+  }
+ 
+#endif
+
   pdf::Bool interpretType3Chars() { return gFalse; }
 
   void drawChar(pdf::gfx::State *state, double x, double y, double dx, double dy, double origin_x, double origin_y,
