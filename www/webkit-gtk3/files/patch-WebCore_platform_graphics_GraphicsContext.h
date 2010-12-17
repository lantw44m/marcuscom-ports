--- WebCore/platform/graphics/GraphicsContext.h.orig	2010-12-16 21:46:30.000000000 +0000
+++ WebCore/platform/graphics/GraphicsContext.h	2010-12-16 22:05:45.000000000 +0000
@@ -90,7 +90,7 @@ typedef void PlatformGraphicsContext;
 #endif
 
 #if PLATFORM(GTK)
-typedef struct _GdkDrawable GdkDrawable;
+typedef struct _GdkWindow GdkWindow;
 typedef struct _GdkEventExpose GdkEventExpose;
 #endif
 
@@ -405,7 +405,7 @@ namespace WebCore {
 
 #if PLATFORM(GTK)
         void setGdkExposeEvent(GdkEventExpose*);
-        GdkDrawable* gdkDrawable() const;
+	GdkWindow* gdkWindow() const;
         GdkEventExpose* gdkExposeEvent() const;
 #endif
 
