--- gnome-panel/panel-toplevel.c.orig	Thu Aug  7 13:11:03 2003
+++ gnome-panel/panel-toplevel.c	Thu Aug  7 13:11:14 2003
@@ -1234,7 +1234,7 @@
 	PanelOrientation  orientation;
 	GdkScreen        *screen;
 	gboolean          topmost, bottommost, leftmost, rightmost;
-	gboolean          geometry_changed = FALSE;;
+	gboolean          geometry_changed = FALSE;
 	int               strut, strut_start, strut_end;
 	int               x, y, width, height;
 	int               monitor_x, monitor_y;
