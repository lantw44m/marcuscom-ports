--- src/nautilus-navigation-window.c	2007/01/11 19:16:19	12693
+++ src/nautilus-navigation-window.c	2007/07/18 22:07:07	13002
@@ -854,8 +854,10 @@
 	g_assert (NAUTILUS_IS_WINDOW (window));
 
 	active = gtk_combo_box_get_active (combo_box);
-	
-	if (active < GPOINTER_TO_INT (g_object_get_data (G_OBJECT (combo_box), "num viewers"))  ) {
+
+	if (active < 0) {
+		return;
+	} else if (active < GPOINTER_TO_INT (g_object_get_data (G_OBJECT (combo_box), "num viewers"))) {
 		activate_nth_short_list_item (window, active);
 	} else {
 		activate_extra_viewer (window);
