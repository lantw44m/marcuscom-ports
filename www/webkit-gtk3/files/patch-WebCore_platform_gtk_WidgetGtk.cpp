--- WebCore/platform/gtk/WidgetGtk.cpp.orig	2010-12-16 23:35:42.000000000 +0000
+++ WebCore/platform/gtk/WidgetGtk.cpp	2010-12-16 23:36:29.000000000 +0000
@@ -60,7 +60,7 @@ void Widget::setFocus(bool focused)
         gtk_widget_grab_focus(platformWidget() ? platformWidget() : GTK_WIDGET(root()->hostWindow()->platformPageClient()));
 }
 
-static GdkDrawable* gdkDrawable(PlatformWidget widget)
+static GdkWindow* gdkWindow(PlatformWidget widget)
 {
     return widget ? gtk_widget_get_window(widget) : 0;
 }
@@ -78,7 +78,7 @@ void Widget::setCursor(const Cursor& cur
     if (platformCursor == lastSetCursor)
         return;
 
-    gdk_window_set_cursor(gdkDrawable(platformWidget()) ? GDK_WINDOW(gdkDrawable(platformWidget())) : gtk_widget_get_window(GTK_WIDGET(root()->hostWindow()->platformPageClient())), platformCursor);
+    gdk_window_set_cursor(gdkWindow(platformWidget()) ? GDK_WINDOW(platformWidget()) : gtk_widget_get_window(GTK_WIDGET(root()->hostWindow()->platformPageClient())), platformCursor);
     lastSetCursor = platformCursor;
 }
 
