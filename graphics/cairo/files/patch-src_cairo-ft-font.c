--- src/cairo-ft-font.c.orig	Tue Aug 16 14:31:13 2005
+++ src/cairo-ft-font.c	Tue Aug 16 14:31:57 2005
@@ -296,9 +296,8 @@ _cairo_ft_unscaled_font_init (cairo_ft_u
 	filename_copy = strdup (filename);
 	if (filename_copy == NULL)
 	    return CAIRO_STATUS_NO_MEMORY;
+        _cairo_ft_unscaled_font_init_key (unscaled, filename_copy, id);
     }
-
-    _cairo_ft_unscaled_font_init_key (unscaled, filename_copy, id);
 
     if (face) {
 	unscaled->from_face = 1;
