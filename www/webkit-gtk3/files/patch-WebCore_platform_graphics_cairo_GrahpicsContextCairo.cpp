--- WebCore/platform/graphics/cairo/GraphicsContextCairo.cpp.orig	2010-12-16 21:44:44.000000000 +0000
+++ WebCore/platform/graphics/cairo/GraphicsContextCairo.cpp	2010-12-16 21:45:54.000000000 +0000
@@ -1121,12 +1121,12 @@ GdkEventExpose* GraphicsContext::gdkExpo
     return m_data->expose;
 }
 
-GdkDrawable* GraphicsContext::gdkDrawable() const
+GdkWindow* GraphicsContext::gdkWindow() const
 {
     if (!m_data->expose)
         return 0;
 
-    return GDK_DRAWABLE(m_data->expose->window);
+    return m_data->expose->window;
 }
 #endif
 
