--- gtk/gtktextattributes.h.orig	2011-09-19 23:32:12.000000000 +0200
+++ gtk/gtktextattributes.h	2011-09-19 23:33:10.000000000 +0200
@@ -104,10 +104,12 @@ struct _GtkTextAppearance
 
   GdkRGBA *rgba[2];
 
+#if defined(__SIZEOF_INT__) && defined(__SIZEOF_POINTER__)
 #if __SIZEOF_INT__ == __SIZEOF_POINTER__
   /* unusable, just for ABI compat */
   guint padding[2];
 #endif
+#endif
 };
 
 struct _GtkTextAttributes
