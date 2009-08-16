--- gir/Gtk-custom.c.orig	2009-08-14 01:50:25.000000000 +0000
+++ gir/Gtk-custom.c	2009-08-14 01:54:04.000000000 +0000
@@ -56,11 +56,13 @@
     return req->height;
 }
 
+#if 0
 const GtkAllocation*
 gtk_widget_get_allocation(const GtkWidget *wdg)
 {
     return &wdg->allocation;
 }
+#endif
 
 GtkAllocation*
 gtk_allocation_new(void)
