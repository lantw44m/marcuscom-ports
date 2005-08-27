===================================================================
RCS file: /cvs/gnome/librsvg/gdk-pixbuf-loader/io-svg.c,v
retrieving revision 1.26
retrieving revision 1.26.2.1
diff -u -r1.26 -r1.26.2.1
--- gdk-pixbuf-loader/io-svg.c	2005/06/24 12:14:56	1.26
+++ gdk-pixbuf-loader/io-svg.c	2005/08/27 03:31:44	1.26.2.1
@@ -191,12 +191,25 @@
 #define GDK_PIXBUF_FORMAT_THREADSAFE (1 << 2)
 #endif
 
+#ifndef GDK_PIXBUF_CHECK_VERSION
+#define GDK_PIXBUF_CHECK_VERSION(major,minor,micro)    \
+    (GDK_PIXBUF_MAJOR > (major) || \
+     (GDK_PIXBUF_MAJOR == (major) && GDK_PIXBUF_MINOR > (minor)) || \
+     (GDK_PIXBUF_MAJOR == (major) && GDK_PIXBUF_MINOR == (minor) && \
+      GDK_PIXBUF_MICRO >= (micro)))
+#endif
+
 void
 fill_info (GdkPixbufFormat *info)
 {
-        static GdkPixbufModulePattern signature[] = {
-                { "<svg", NULL, 100 },
-                { "<!DOCTYPE svg", NULL, 100 },
+        static GdkPixbufModulePattern signature_old[] = {
+                { (unsigned char*) "<svg", NULL, 100 },
+                { (unsigned char*) "<!DOCTYPE svg", NULL, 100 },
+                { NULL, NULL, 0 }
+        };
+        static GdkPixbufModulePattern signature_new[] = {
+                { (unsigned char*) " <svg", (unsigned char*) "*    ", 100 },
+                { (unsigned char*) " <!DOCTYPE svg", (unsigned char*) "*             ", 100 },
                 { NULL, NULL, 0 }
         };
         static gchar *mime_types[] = { /* yes folks, i actually have run into all of these in the wild... */
@@ -215,7 +228,11 @@
         };
 
         info->name        = "svg";
-        info->signature   = signature;
+        if (GDK_PIXBUF_CHECK_VERSION (2, 7, 4)) {
+                info->signature = signature_new;
+        } else {
+                info->signature = signature_old;
+        }
         info->description = _("Scalable Vector Graphics");
         info->mime_types  = mime_types;
         info->extensions  = extensions;
