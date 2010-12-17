--- WebCore/plugins/gtk/PluginViewGtk.cpp.orig	2010-12-16 23:38:27.000000000 +0000
+++ WebCore/plugins/gtk/PluginViewGtk.cpp	2010-12-16 23:39:05.000000000 +0000
@@ -114,7 +114,7 @@ static Window getRootWindow(Frame* paren
 {
     GtkWidget* parentWidget = parentFrame->view()->hostWindow()->platformPageClient();
     GdkScreen* gscreen = gtk_widget_get_screen(parentWidget);
-    return GDK_WINDOW_XWINDOW(gdk_screen_get_root_window(gscreen));
+    return GDK_WINDOW_XID(gdk_screen_get_root_window(gscreen));
 }
 #endif
 
@@ -325,7 +325,7 @@ void PluginView::initXEvent(XEvent* xEve
     // but does in the case of KeyPress, KeyRelease, ButtonPress, ButtonRelease, and MotionNotify
     // events; thus, this is right:
     GtkWidget* widget = m_parentFrame->view()->hostWindow()->platformPageClient();
-    xEvent->xany.window = widget ? GDK_WINDOW_XWINDOW(gtk_widget_get_window(widget)) : 0;
+    xEvent->xany.window = widget ? GDK_WINDOW_XID(gtk_widget_get_window(widget)) : 0;
 }
 
 static void setXButtonEventSpecificFields(XEvent* xEvent, MouseEvent* event, const IntPoint& postZoomPos, Frame* parentFrame)
@@ -635,7 +635,7 @@ bool PluginView::platformGetValue(NPNVar
 #if defined(XP_UNIX)
             void* w = reinterpret_cast<void*>(value);
             GtkWidget* widget = m_parentFrame->view()->hostWindow()->platformPageClient();
-            *((XID *)w) = GDK_WINDOW_XWINDOW(gtk_widget_get_window(widget));
+            *((XID *)w) = GDK_WINDOW_XID(gtk_widget_get_window(widget));
 #endif
 #ifdef GDK_WINDOWING_WIN32
             HGDIOBJ* w = reinterpret_cast<HGDIOBJ*>(value);
