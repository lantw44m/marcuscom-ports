--- gnomine/minefield.c.orig	Sun Jul 13 15:45:21 2003
+++ gnomine/minefield.c	Sun Jul 13 15:45:38 2003
@@ -226,11 +226,11 @@
 static void gtk_minefield_size_allocate (GtkWidget     *widget,
 				 	 GtkAllocation *allocation)
 {
-        widget->allocation = *allocation;
         guint minesize, width, height;
         guint xofs, yofs;
         GtkMineField * mfield;
 
+        widget->allocation = *allocation;
         mfield = GTK_MINEFIELD (widget);
         
 	if (GTK_WIDGET_REALIZED (widget)) {
