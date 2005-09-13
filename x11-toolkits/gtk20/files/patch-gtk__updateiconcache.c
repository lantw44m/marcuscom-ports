--- gtk/updateiconcache.c.orig	Tue Sep 13 22:59:51 2005
+++ gtk/updateiconcache.c	Tue Sep 13 22:58:33 2005
@@ -144,9 +144,9 @@
   if (image->flags == HAS_ICON_FILE)
     {
       g_free (key);
-      g_free (image);
       g_free (image->attach_points);
       g_strfreev (image->display_names);
+      g_free (image);
 
       return TRUE;
     }
