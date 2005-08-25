--- gdk/gdkscreen.c.orig	Tue Aug 23 23:29:05 2005
+++ gdk/gdkscreen.c	Thu Aug 25 13:18:01 2005
@@ -29,7 +29,7 @@
 #include "gdkalias.h"
 
 static void gdk_screen_class_init  (GdkScreenClass *klass);
-static void gdk_screen_init        (GdkScreen      *screen);
+static void gdk_screen_init_instance (GTypeInstance *instance, gpointer g_class);
 static void gdk_screen_dispose     (GObject        *object);
 static void gdk_screen_finalize    (GObject        *object);
 
@@ -53,14 +53,14 @@ gdk_screen_get_type (void)
       static const GTypeInfo object_info =
 	{
 	  sizeof (GdkScreenClass),
-	  (GBaseInitFunc) gdk_screen_init,
+	  (GBaseInitFunc) NULL,
 	  (GBaseFinalizeFunc) NULL,
 	  (GClassInitFunc) gdk_screen_class_init,
 	  NULL,			/* class_finalize */
 	  NULL,			/* class_data */
 	  sizeof (GdkScreen),
 	  0,			/* n_preallocs */
-	  (GInstanceInitFunc) NULL,
+	  (GInstanceInitFunc) gdk_screen_init_instance,
 	};
       
       object_type = g_type_register_static (G_TYPE_OBJECT,
@@ -101,9 +101,10 @@ gdk_screen_class_init (GdkScreenClass *k
 }
 
 static void
-gdk_screen_init (GdkScreen *screen)
+gdk_screen_init_instance (GTypeInstance *instance,
+			  gpointer g_class)
 {
-    screen->resolution = -1;
+  GDK_SCREEN (instance)->resolution = -1.;
 }
 
 static void
@@ -407,7 +408,7 @@ gdk_screen_set_resolution_libgtk_only (G
     if (dpi >= 0)
 	screen->resolution = dpi;
     else
-	screen->resolution = -1;
+	screen->resolution = -1.;
 }
 
 /**
@@ -423,7 +424,7 @@ gdk_screen_set_resolution_libgtk_only (G
 gdouble
 gdk_screen_get_resolution_libgtk_only (GdkScreen *screen)
 {
-    g_return_val_if_fail (GDK_IS_SCREEN (screen), -1);
+    g_return_val_if_fail (GDK_IS_SCREEN (screen), -1.);
 
     return screen->resolution;
 }
