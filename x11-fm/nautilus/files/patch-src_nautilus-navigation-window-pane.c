--- src/nautilus-navigation-window-pane.c.orig	2010-08-18 11:05:15.000000000 +0200
+++ src/nautilus-navigation-window-pane.c	2010-08-18 11:06:41.000000000 +0200
@@ -457,8 +457,8 @@ notebook_popup_menu_cb (GtkWidget *widge
 }
 
 static gboolean
-notebook_switch_page_cb (GtkNotebook *notebook,
-			 GtkNotebookPage *page,
+notebook_switch_page_cb (GtkWidget *notebook,
+			 GtkWidget *page,
 			 unsigned int page_num,
 			 NautilusNavigationWindowPane *pane)
 {
@@ -480,7 +480,7 @@ notebook_switch_page_cb (GtkNotebook *no
 void
 nautilus_navigation_window_pane_remove_page (NautilusNavigationWindowPane *pane, int page_num)
 {
-	GtkNotebook *notebook;
+	GtkWidget *notebook;
 	notebook = GTK_NOTEBOOK (pane->notebook);
 
 	g_signal_handlers_block_by_func (notebook,
