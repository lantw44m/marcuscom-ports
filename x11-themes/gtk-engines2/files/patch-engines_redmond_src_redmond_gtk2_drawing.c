--- engines/redmond/src/redmond_gtk2_drawing.c.orig	Thu Dec 23 16:16:27 2004
+++ engines/redmond/src/redmond_gtk2_drawing.c	Thu Dec 23 16:18:06 2004
@@ -1581,9 +1581,13 @@
              gint height, 
              GtkOrientation orientation)
 {
+  gboolean left_cutoff, top_cutoff, bottom_cutoff, right_cutoff;
   g_return_if_fail(sanitize_parameters(style, window, &width, &height));
   
-  gboolean left_cutoff = FALSE, right_cutoff = FALSE, top_cutoff = FALSE, bottom_cutoff = FALSE;
+  left_cutoff = FALSE;
+  right_cutoff = FALSE;
+  top_cutoff = FALSE;
+  bottom_cutoff = FALSE;
   
   if (IS_BONOBO_DOCK_ITEM_GRIP(widget) && 
      (gtk_widget_get_direction (widget) == GTK_TEXT_DIR_RTL) && 
