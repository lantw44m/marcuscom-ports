--- WebCore/plugins/gtk/gtk2xtbin.c.orig	2010-12-16 23:40:35.000000000 +0000
+++ WebCore/plugins/gtk/gtk2xtbin.c	2010-12-16 23:45:40.000000000 +0000
@@ -285,7 +285,7 @@ gtk_xtbin_realize (GtkWidget *widget)
   xtbin = GTK_XTBIN (widget);
 
   /* caculate the allocation before realize */
-  gdk_window_get_geometry(xtbin->parent_window, &x, &y, &w, &h, &d);
+  gdk_window_get_geometry(xtbin->parent_window, &x, &y, &w, &h);
   allocation.width = w;
   allocation.height = h;
   gtk_widget_size_allocate (widget, &allocation);
@@ -346,7 +346,7 @@ gtk_xtbin_new (GtkWidget *parent_widget,
   screen = gtk_widget_get_screen(parent_widget);
   visual = gdk_screen_get_system_visual(screen);
   colormap = XCreateColormap(GDK_DISPLAY_XDISPLAY(gdk_screen_get_display(screen)),
-                             GDK_WINDOW_XWINDOW(gdk_screen_get_root_window(screen)),
+                             GDK_WINDOW_XID(gdk_screen_get_root_window(screen)),
                              GDK_VISUAL_XVISUAL(visual), AllocNone);
 
   xt_client_init(&(xtbin->xtclient), 
