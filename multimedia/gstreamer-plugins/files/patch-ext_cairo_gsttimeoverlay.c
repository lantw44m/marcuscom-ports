--- ext/cairo/gsttimeoverlay.c.orig	Sun Jun 12 10:43:45 2005
+++ ext/cairo/gsttimeoverlay.c	Sun Jun 12 10:44:04 2005
@@ -34,41 +34,16 @@
 
 #include <cairo.h>
 
-/* This is for cairo 0.4, remove once we require 0.5 */
-#ifndef CAIRO_API_SHAKEUP_FLAG_DAY
-#define cairo_set_source_rgba(cr,red,green,blue,alpha) {\
-    cairo_set_rgb_color(cr,red,green,blue); \
-    cairo_set_alpha(cr,alpha); }
-#endif
-
-/* GstTimeoverlay signals and args */
-enum
-{
-  /* FILL ME */
-  LAST_SIGNAL
-};
-
-enum
-{
-  ARG_0
-      /* FILL ME */
-};
-
 static void gst_timeoverlay_base_init (gpointer g_class);
 static void gst_timeoverlay_class_init (gpointer g_class, gpointer class_data);
 static void gst_timeoverlay_init (GTypeInstance * instance, gpointer g_class);
 
-static void gst_timeoverlay_set_property (GObject * object, guint prop_id,
-    const GValue * value, GParamSpec * pspec);
-static void gst_timeoverlay_get_property (GObject * object, guint prop_id,
-    GValue * value, GParamSpec * pspec);
-
 static void gst_timeoverlay_planar411 (GstVideofilter * videofilter, void *dest,
     void *src);
 static void gst_timeoverlay_setup (GstVideofilter * videofilter);
 
 GType
-gst_timeoverlay_get_type (void)
+gst_cairotimeoverlay_get_type (void)
 {
   static GType timeoverlay_type = 0;
 
@@ -86,7 +61,7 @@
     };
 
     timeoverlay_type = g_type_register_static (GST_TYPE_VIDEOFILTER,
-        "GstTimeoverlay", &timeoverlay_info, 0);
+        "GstCairoTimeOverlay", &timeoverlay_info, 0);
   }
   return timeoverlay_type;
 }
@@ -127,16 +102,6 @@
   gobject_class = G_OBJECT_CLASS (g_class);
   videofilter_class = GST_VIDEOFILTER_CLASS (g_class);
 
-#if 0
-  g_object_class_install_property (gobject_class, ARG_METHOD,
-      g_param_spec_enum ("method", "method", "method",
-          GST_TYPE_TIMEOVERLAY_METHOD, GST_TIMEOVERLAY_METHOD_1,
-          G_PARAM_READWRITE));
-#endif
-
-  gobject_class->set_property = gst_timeoverlay_set_property;
-  gobject_class->get_property = gst_timeoverlay_get_property;
-
   videofilter_class->setup = gst_timeoverlay_setup;
 }
 
@@ -154,70 +119,29 @@
 }
 
 static void
-gst_timeoverlay_set_property (GObject * object, guint prop_id,
-    const GValue * value, GParamSpec * pspec)
-{
-  GstTimeoverlay *src;
-
-  /* it's not null if we got it, but it might not be ours */
-  g_return_if_fail (GST_IS_TIMEOVERLAY (object));
-  src = GST_TIMEOVERLAY (object);
-
-  GST_DEBUG ("gst_timeoverlay_set_property");
-  switch (prop_id) {
-#if 0
-    case ARG_METHOD:
-      src->method = g_value_get_enum (value);
-      break;
-#endif
-    default:
-      break;
-  }
-}
-
-static void
-gst_timeoverlay_get_property (GObject * object, guint prop_id, GValue * value,
-    GParamSpec * pspec)
-{
-  GstTimeoverlay *src;
-
-  /* it's not null if we got it, but it might not be ours */
-  g_return_if_fail (GST_IS_TIMEOVERLAY (object));
-  src = GST_TIMEOVERLAY (object);
-
-  switch (prop_id) {
-#if 0
-    case ARG_METHOD:
-      g_value_set_enum (value, src->method);
-      break;
-#endif
-    default:
-      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
-      break;
-  }
-}
-
-static void
 gst_timeoverlay_setup (GstVideofilter * videofilter)
 {
   GstTimeoverlay *timeoverlay;
   cairo_font_extents_t font_extents;
+  cairo_surface_t *surface;
+  cairo_t *cr;
 
   g_return_if_fail (GST_IS_TIMEOVERLAY (videofilter));
   timeoverlay = GST_TIMEOVERLAY (videofilter);
 
-  /* if any setup needs to be done, do it here */
-
-  timeoverlay->cr = cairo_create ();
+  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 64, 64);
+  cr = cairo_create (surface);
 
-  cairo_set_rgb_color (timeoverlay->cr, 0, 0, 0);
+  cairo_set_source_rgb (cr, 0, 0, 0);
 
-  cairo_select_font (timeoverlay->cr, "monospace", 0, 0);
-  cairo_scale_font (timeoverlay->cr, 20);
+  cairo_select_font_face (cr, "monospace", 0, 0);
+  cairo_set_font_size (cr, 20);
 
-  cairo_current_font_extents (timeoverlay->cr, &font_extents);
+  cairo_font_extents (cr, &font_extents);
   timeoverlay->text_height = font_extents.height;
 
+  cairo_destroy (cr);
+  cairo_surface_destroy (surface);
 }
 
 static char *
@@ -251,8 +175,10 @@
   int b_width;
   char *string;
   int i, j;
-  char *image;
+  unsigned char *image;
   cairo_text_extents_t extents;
+  cairo_surface_t *surface;
+  cairo_t *cr;
 
   g_return_if_fail (GST_IS_TIMEOVERLAY (videofilter));
   timeoverlay = GST_TIMEOVERLAY (videofilter);
@@ -266,32 +192,40 @@
 
   image = g_malloc (4 * width * timeoverlay->text_height);
 
-  cairo_set_target_image (timeoverlay->cr, image, CAIRO_FORMAT_ARGB32,
+  surface = cairo_image_surface_create_for_data (image, CAIRO_FORMAT_ARGB32,
       width, timeoverlay->text_height, width * 4);
 
-  cairo_save (timeoverlay->cr);
-  cairo_rectangle (timeoverlay->cr, 0, 0, width, timeoverlay->text_height);
-  cairo_set_source_rgba (timeoverlay->cr, 0, 0, 0, 0);
-
-  cairo_set_operator (timeoverlay->cr, CAIRO_OPERATOR_SRC);
-  cairo_fill (timeoverlay->cr);
-  cairo_restore (timeoverlay->cr);
-
-  cairo_save (timeoverlay->cr);
-  cairo_text_extents (timeoverlay->cr, (guchar *) string, &extents);
-
-  cairo_set_rgb_color (timeoverlay->cr, 1, 1, 1);
-  cairo_move_to (timeoverlay->cr, 0, timeoverlay->text_height - 2);
-  cairo_show_text (timeoverlay->cr, (guchar *) string);
+  cr = cairo_create (surface);
+
+  cairo_set_source_rgb (cr, 0, 0, 0);
+  cairo_select_font_face (cr, "monospace", 0, 0);
+  cairo_set_font_size (cr, 20);
+
+  cairo_save (cr);
+
+  cairo_rectangle (cr, 0, 0, width, timeoverlay->text_height);
+  cairo_set_source_rgba (cr, 0, 0, 0, 0);
+
+  cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
+  cairo_fill (cr);
+  cairo_restore (cr);
+
+  cairo_save (cr);
+  cairo_text_extents (cr, string, &extents);
+
+  cairo_set_source_rgb (cr, 1, 1, 1);
+  cairo_move_to (cr, 0, timeoverlay->text_height - 2);
+  cairo_show_text (cr, string);
   g_free (string);
+
 #if 0
-  cairo_text_path (timeoverlay->cr, string);
-  cairo_set_rgb_color (timeoverlay->cr, 1, 1, 1);
-  cairo_set_line_width (timeoverlay->cr, 1.0);
-  cairo_stroke (timeoverlay->cr);
+  cairo_text_path (cr, string);
+  cairo_set_source_rgb (cr, 1, 1, 1);
+  cairo_set_line_width (cr, 1.0);
+  cairo_stroke (cr);
 #endif
 
-  cairo_restore (timeoverlay->cr);
+  cairo_restore (cr);
 
   b_width = extents.width;
   if (b_width > width)
@@ -310,4 +244,7 @@
   }
 
   g_free (image);
+
+  cairo_destroy (cr);
+  cairo_surface_destroy (surface);
 }
