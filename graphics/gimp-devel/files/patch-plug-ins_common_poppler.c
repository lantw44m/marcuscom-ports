--- plug-ins/common/poppler.c.orig	Wed Aug 17 08:05:13 2005
+++ plug-ins/common/poppler.c	Wed Aug 17 08:11:52 2005
@@ -487,8 +496,7 @@ load_image (PopplerDocument  *doc,
       poppler_page_render_to_pixbuf (page, 0, 0,
                                      width, height,
                                      scale,
-                                     buf,
-                                     0, 0);
+                                     buf);
 
       g_object_get (G_OBJECT (page), "label", &page_label, NULL);
 
@@ -539,8 +551,7 @@ get_thumbnail (PopplerDocument *doc,
       poppler_page_render_to_pixbuf (page, 0, 0,
                                      width, height,
                                      scale,
-                                     pixbuf,
-                                     0, 0);
+                                     pixbuf);
     }
 
   g_object_unref (page);
