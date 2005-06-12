--- ext/cairo/gsttextoverlay.c.orig	Sun Jun 12 10:43:32 2005
+++ ext/cairo/gsttextoverlay.c	Sun Jun 12 10:44:04 2005
@@ -84,18 +84,9 @@
 
 static GstElementClass *parent_class = NULL;
 
-/*static guint gst_textoverlay_signals[LAST_SIGNAL] = { 0 }; */
-
-/* This is for cairo 0.4, remove once we require 0.5 */
-#ifndef CAIRO_API_SHAKEUP_FLAG_DAY
-#define cairo_set_source_rgba(cr,red,green,blue,alpha) {\
-    cairo_set_rgb_color(cr,red,green,blue); \
-    cairo_set_alpha(cr,alpha); }
-#endif
-
 
 GType
-gst_textoverlay_get_type (void)
+gst_cairotextoverlay_get_type (void)
 {
   static GType textoverlay_type = 0;
 
@@ -113,7 +104,7 @@
     };
 
     textoverlay_type =
-        g_type_register_static (GST_TYPE_ELEMENT, "GstTextOverlay",
+        g_type_register_static (GST_TYPE_ELEMENT, "GstCairoTextOverlay",
         &textoverlay_info, 0);
   }
   return textoverlay_type;
@@ -221,30 +212,37 @@
     int textlen)
 {
   cairo_text_extents_t extents;
+  cairo_surface_t *surface;
+  cairo_t *cr;
   char *string;
   double x, y;
 
   string = g_strndup (text, textlen);
 
-  if (overlay->text_fill_image)
-    g_free (overlay->text_fill_image);
   overlay->text_fill_image =
-      g_malloc (4 * overlay->width * overlay->text_height);
-  cairo_set_target_image (overlay->cr, (gchar *) overlay->text_fill_image,
+      g_realloc (overlay->text_fill_image,
+      4 * overlay->width * overlay->text_height);
+
+  surface = cairo_image_surface_create_for_data (overlay->text_fill_image,
       CAIRO_FORMAT_ARGB32, overlay->width, overlay->text_height,
       overlay->width * 4);
 
-  cairo_save (overlay->cr);
-  cairo_rectangle (overlay->cr, 0, 0, overlay->width, overlay->text_height);
-  cairo_set_source_rgba (overlay->cr, 0, 0, 0, 1.0);
-
-  cairo_set_operator (overlay->cr, CAIRO_OPERATOR_SRC);
-  cairo_fill (overlay->cr);
-  cairo_restore (overlay->cr);
-
-  cairo_save (overlay->cr);
-  cairo_text_extents (overlay->cr, (guchar *) string, &extents);
-  cairo_set_source_rgba (overlay->cr, 1, 1, 1, 1.0);
+  cr = cairo_create (surface);
+
+  cairo_select_font_face (cr, overlay->font, overlay->slant, overlay->weight);
+  cairo_set_font_size (cr, overlay->scale);
+
+  cairo_save (cr);
+  cairo_rectangle (cr, 0, 0, overlay->width, overlay->text_height);
+  cairo_set_source_rgba (cr, 0, 0, 0, 1.0);
+
+  cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
+  cairo_fill (cr);
+  cairo_restore (cr);
+
+  cairo_save (cr);
+  cairo_text_extents (cr, string, &extents);
+  cairo_set_source_rgba (cr, 1, 1, 1, 1.0);
 
   switch (overlay->halign) {
     case GST_TEXT_OVERLAY_HALIGN_LEFT:
@@ -260,42 +258,53 @@
       x = 0;
   }
   y = overlay->text_height - 2;
-  cairo_move_to (overlay->cr, x, y);
-  cairo_show_text (overlay->cr, (guchar *) string);
-  cairo_restore (overlay->cr);
+  cairo_move_to (cr, x, y);
+  cairo_show_text (cr, string);
+  cairo_restore (cr);
+
+  cairo_destroy (cr);
+  cairo_surface_destroy (surface);
+
+  /* ----------- */
 
-  if (overlay->text_outline_image)
-    g_free (overlay->text_outline_image);
   overlay->text_outline_image =
-      g_malloc (4 * overlay->width * overlay->text_height);
-  cairo_set_target_image (overlay->cr, (gchar *) overlay->text_outline_image,
+      g_realloc (overlay->text_outline_image,
+      4 * overlay->width * overlay->text_height);
+
+  surface = cairo_image_surface_create_for_data (overlay->text_outline_image,
       CAIRO_FORMAT_ARGB32, overlay->width, overlay->text_height,
       overlay->width * 4);
 
-  cairo_save (overlay->cr);
-  cairo_rectangle (overlay->cr, 0, 0, overlay->width, overlay->text_height);
-  cairo_set_source_rgba (overlay->cr, 0, 0, 0, 1.0);
-  cairo_set_operator (overlay->cr, CAIRO_OPERATOR_SRC);
-  cairo_fill (overlay->cr);
-  cairo_restore (overlay->cr);
-
-  cairo_save (overlay->cr);
-  cairo_move_to (overlay->cr, x, y);
-  cairo_set_source_rgba (overlay->cr, 1, 1, 1, 1.0);
-  cairo_set_line_width (overlay->cr, 1.0);
-  cairo_text_path (overlay->cr, (guchar *) string);
-  cairo_stroke (overlay->cr);
-  cairo_restore (overlay->cr);
+  cr = cairo_create (surface);
 
-  g_free (string);
-}
+  cairo_select_font_face (cr, overlay->font, overlay->slant, overlay->weight);
+  cairo_set_font_size (cr, overlay->scale);
 
-/* static GstPadLinkReturn */
-/* gst_textoverlay_text_sinkconnect (GstPad *pad, GstCaps *caps) */
-/* { */
-/*     return GST_PAD_LINK_DONE; */
-/* } */
+/*
+  cairo_set_target_image (cr, (gchar*) overlay->text_outline_image,
+      CAIRO_FORMAT_ARGB32, overlay->width, overlay->text_height,
+      overlay->width * 4);
+*/
+  cairo_save (cr);
+  cairo_rectangle (cr, 0, 0, overlay->width, overlay->text_height);
+  cairo_set_source_rgba (cr, 0, 0, 0, 1.0);
+  cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
+  cairo_fill (cr);
+  cairo_restore (cr);
+
+  cairo_save (cr);
+  cairo_move_to (cr, x, y);
+  cairo_set_source_rgba (cr, 1, 1, 1, 1.0);
+  cairo_set_line_width (cr, 1.0);
+  cairo_text_path (cr, (guchar *) string);
+  cairo_stroke (cr);
+  cairo_restore (cr);
+
+  g_free (string);
 
+  cairo_destroy (cr);
+  cairo_surface_destroy (surface);
+}
 
 static GstPadLinkReturn
 gst_textoverlay_video_sinkconnect (GstPad * pad, const GstCaps * caps)
@@ -542,17 +551,24 @@
 gst_textoverlay_font_init (GstTextOverlay * overlay)
 {
   cairo_font_extents_t font_extents;
+  cairo_surface_t *surface;
+  cairo_t *cr;
+
+  surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 64, 64);
+  cr = cairo_create (surface);
 
-  cairo_select_font (overlay->cr, overlay->font, overlay->slant,
-      overlay->weight);
-  cairo_scale_font (overlay->cr, overlay->scale);
+  cairo_select_font_face (cr, overlay->font, overlay->slant, overlay->weight);
+  cairo_set_font_size (cr, overlay->scale);
 
-  cairo_current_font_extents (overlay->cr, &font_extents);
+  cairo_font_extents (cr, &font_extents);
   overlay->text_height = font_extents.height;
   if (overlay->text_height & 1)
     overlay->text_height++;
 
   overlay->need_render = TRUE;
+
+  cairo_destroy (cr);
+  cairo_surface_destroy (surface);
 }
 
 static GstElementStateReturn
@@ -581,10 +597,8 @@
 {
   GstTextOverlay *overlay = GST_TEXTOVERLAY (object);
 
-  if (overlay->cr) {
-    cairo_destroy (overlay->cr);
-  }
-
+  g_free (overlay->font);
+  g_free (overlay->default_text);
   G_OBJECT_CLASS (parent_class)->finalize (object);
 }
 
@@ -611,8 +625,6 @@
       (&textoverlay_src_template_factory), "src");
   gst_element_add_pad (GST_ELEMENT (overlay), overlay->srcpad);
 
-  overlay->cr = cairo_create ();
-
   overlay->halign = GST_TEXT_OVERLAY_HALIGN_CENTER;
   overlay->valign = GST_TEXT_OVERLAY_VALIGN_BASELINE;
   overlay->x0 = overlay->y0 = 25;
@@ -635,17 +647,14 @@
 {
   GstTextOverlay *overlay;
 
-  /* it's not null if we got it, but it might not be ours */
   g_return_if_fail (GST_IS_TEXTOVERLAY (object));
   overlay = GST_TEXTOVERLAY (object);
 
   switch (prop_id) {
 
     case ARG_TEXT:
-      if (overlay->default_text) {
-        g_free (overlay->default_text);
-      }
-      overlay->default_text = g_strdup (g_value_get_string (value));
+      g_free (overlay->default_text);
+      overlay->default_text = g_value_dup_string (value);
       overlay->need_render = TRUE;
       break;
 
@@ -684,9 +693,8 @@
       break;
 
     case ARG_FONT_DESC:
-      if (overlay->font)
-        g_free (overlay->font);
-      overlay->font = g_strdup (g_value_get_string (value));
+      g_free (overlay->font);
+      overlay->font = g_value_dup_string (value);
       gst_textoverlay_font_init (overlay);
       break;
 
