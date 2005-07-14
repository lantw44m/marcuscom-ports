--- src/totem-volume.c.orig	Thu Jul 14 00:10:58 2005
+++ src/totem-volume.c	Thu Jul 14 00:11:16 2005
@@ -282,7 +282,7 @@ totem_volume_button_press (GtkWidget    
   button->timeout = TRUE;
 
   /* position (needs widget to be shown already) */
-  v = lrintf (totem_volume_button_get_value (button));
+  v = (long) rintf (totem_volume_button_get_value (button));
   x += widget->allocation.x;
   x += (widget->allocation.width - button->dock->allocation.width) / 2;
   y += widget->allocation.y;
@@ -569,7 +569,7 @@ totem_volume_scale_value_changed (GtkRan
   char *s;
 
   /* update label */
-  s = g_strdup_printf ("%d", lrintf (val));
+  s = g_strdup_printf ("%d", (long) rintf (val));
   gtk_button_set_label (GTK_BUTTON (button), s);
   g_free (s);
 #else
