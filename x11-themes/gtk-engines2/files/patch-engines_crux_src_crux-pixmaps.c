--- engines/crux/crux-pixmaps.c.orig	Thu Dec 23 16:13:44 2004
+++ engines/crux/crux-pixmaps.c	Thu Dec 23 16:14:09 2004
@@ -329,8 +329,9 @@
 static GdkPixbuf *
 load_image (const char *file)
 {
+    GdkPixbuf *pixbuf;
 	printf("%s\n", file);	
-    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file (file, NULL);
+    pixbuf = gdk_pixbuf_new_from_file (file, NULL);
     if (pixbuf != 0)
       return pixbuf;
       
