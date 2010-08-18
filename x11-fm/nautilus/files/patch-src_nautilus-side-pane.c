--- src/nautilus-side-pane.c.orig	2010-08-18 11:09:43.000000000 +0200
+++ src/nautilus-side-pane.c	2010-08-18 11:10:05.000000000 +0200
@@ -90,7 +90,7 @@ side_panel_free (SidePanel *panel)
 
 static void
 switch_page_callback (GtkWidget *notebook,
-		      GtkNotebookPage *page,
+		      GtkWidget *page,
 		      guint page_num,
 		      gpointer user_data)
 {
