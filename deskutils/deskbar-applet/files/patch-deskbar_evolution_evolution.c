--- deskbar/evolution/evolution.c.orig	Tue Jul 25 23:49:21 2006
+++ deskbar/evolution/evolution.c	Tue Jul 25 23:49:57 2006
@@ -104,7 +104,7 @@ pixbuf_from_contact (EContact *contact)
 
 		loader = gdk_pixbuf_loader_new ();
 
-		if (gdk_pixbuf_loader_write (loader, (guchar *) photo->data, photo->length, NULL))
+		if (gdk_pixbuf_loader_write (loader, (guchar *) photo->data.inlined.data, photo->data.inlined.length, NULL))
 			pixbuf = gdk_pixbuf_loader_get_pixbuf (loader);
 
 		if (pixbuf) {
