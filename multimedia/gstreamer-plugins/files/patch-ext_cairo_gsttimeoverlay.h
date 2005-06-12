--- ext/cairo/gsttimeoverlay.h.orig	Sun Jun 12 10:43:50 2005
+++ ext/cairo/gsttimeoverlay.h	Sun Jun 12 10:44:04 2005
@@ -31,7 +31,7 @@
 G_BEGIN_DECLS
 
 #define GST_TYPE_TIMEOVERLAY \
-  (gst_timeoverlay_get_type())
+  (gst_cairotimeoverlay_get_type())
 #define GST_TIMEOVERLAY(obj) \
   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_TIMEOVERLAY,GstTimeoverlay))
 #define GST_TIMEOVERLAY_CLASS(klass) \
@@ -46,17 +46,14 @@
 
 struct _GstTimeoverlay {
   GstVideofilter videofilter;
-
-  cairo_t *cr;
   int text_height;
-
 };
 
 struct _GstTimeoverlayClass {
   GstVideofilterClass parent_class;
 };
 
-GType gst_timeoverlay_get_type(void);
+GType gst_cairotimeoverlay_get_type(void);
 
 G_END_DECLS
 
