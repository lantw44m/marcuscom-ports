--- src/marlin-window-menu.c.orig	Wed Aug  4 23:47:26 2004
+++ src/marlin-window-menu.c	Wed Aug  4 23:47:43 2004
@@ -634,7 +634,7 @@
 	GtkWidget *editor, *dialog;
 	EphyToolbarsModel *model;
 	Toolbar *toolbar;
-	GtkUIManager *ui_manager = marlin_window_get_menu_merge (MARLIN_WINDOW (data));;
+	GtkUIManager *ui_manager = marlin_window_get_menu_merge (MARLIN_WINDOW (data));
 	char *xml;
 
 	toolbar = marlin_window_get_toolbar (MARLIN_WINDOW (data));
