--- WebCore/platform/gtk/PlatformScreenGtk.cpp.orig	2010-12-16 23:22:44.000000000 +0000
+++ WebCore/platform/gtk/PlatformScreenGtk.cpp	2010-12-16 23:33:34.000000000 +0000
@@ -121,7 +121,7 @@ FloatRect screenAvailableRect(Widget* wi
     if (!gtk_widget_get_realized(container))
         return screenRect(widget);
 
-    GdkDrawable* rootWindow = GDK_DRAWABLE(gtk_widget_get_root_window(container));
+    GdkWindow* rootWindow = gtk_widget_get_root_window(container);
     GdkDisplay* display = gdk_window_get_display(rootWindow);
     Atom xproperty = gdk_x11_get_xatom_by_name_for_display(display, "_NET_WORKAREA");
 
@@ -130,7 +130,7 @@ FloatRect screenAvailableRect(Widget* wi
     long *workAreaPos = NULL;
     unsigned long retNItems;
     unsigned long retAfter;
-    int xRes = XGetWindowProperty(GDK_DISPLAY_XDISPLAY(display), GDK_WINDOW_XWINDOW(rootWindow), xproperty,
+    int xRes = XGetWindowProperty(GDK_DISPLAY_XDISPLAY(display), GDK_WINDOW_XID(rootWindow), xproperty,
         0, 4, FALSE, XA_CARDINAL, &retType, &retFormat, &retNItems, &retAfter, (guchar**)&workAreaPos);
 
     FloatRect rect;
