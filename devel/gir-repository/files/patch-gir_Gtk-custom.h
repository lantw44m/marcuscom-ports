--- gir/Gtk-custom.h.orig	2009-08-14 01:50:28.000000000 +0000
+++ gir/Gtk-custom.h	2009-08-14 01:54:27.000000000 +0000
@@ -15,7 +15,9 @@
 GtkRequisition* gtk_requisition_new                   (void);
 int             gtk_requisition_get_width             (const GtkRequisition *req);
 int             gtk_requisition_get_height            (const GtkRequisition *req);
+#if 0
 const GtkAllocation*  gtk_widget_get_allocation       (const GtkWidget *wdg);
+#endif
 GtkAllocation*  gtk_allocation_new                    (void);
 int             gtk_allocation_get_x                  (const GtkAllocation *all);
 int             gtk_allocation_get_y                  (const GtkAllocation *all);
