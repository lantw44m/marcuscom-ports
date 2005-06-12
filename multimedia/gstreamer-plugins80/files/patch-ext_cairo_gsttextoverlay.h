--- ext/cairo/gsttextoverlay.h.orig	Sun Jun 12 10:43:36 2005
+++ ext/cairo/gsttextoverlay.h	Sun Jun 12 10:44:04 2005
@@ -10,7 +10,7 @@
 GST_DEBUG_CATEGORY_EXTERN (cairo_debug);
 #define GST_CAT_DEFAULT cairo_debug
 
-#define GST_TYPE_TEXTOVERLAY           (gst_textoverlay_get_type())
+#define GST_TYPE_TEXTOVERLAY           (gst_cairotextoverlay_get_type())
 #define GST_TEXTOVERLAY(obj)           (G_TYPE_CHECK_INSTANCE_CAST((obj),\
                                         GST_TYPE_TEXTOVERLAY, GstTextOverlay))
 #define GST_TEXTOVERLAY_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),\
@@ -56,7 +56,6 @@
     gint                  y0;
     gchar		 *default_text;
 
-    cairo_t *cr;
     guchar *text_fill_image;
     guchar *text_outline_image;
     int text_height;
@@ -75,7 +74,7 @@
     GstElementClass parent_class;
 };
 
-GType gst_textoverlay_get_type(void) G_GNUC_CONST;
+GType gst_cairotextoverlay_get_type(void) G_GNUC_CONST;
 
 G_END_DECLS
 
