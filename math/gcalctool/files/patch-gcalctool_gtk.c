--- gcalctool/gtk.c.orig	Mon Jul 26 22:17:31 2004
+++ gcalctool/gtk.c	Mon Jul 26 22:18:21 2004
@@ -441,10 +441,10 @@
 void 
 update_statusbar(gchar *text, const gchar *imagename)
 {
-  assert(text);
-  assert(imagename);
 
   GtkImage *image = GTK_IMAGE(X->status_image);
+  assert(text);
+  assert(imagename);
   assert(image);
   gtk_image_set_from_stock(image, imagename, GTK_ICON_SIZE_BUTTON);
   gtk_statusbar_pop(GTK_STATUSBAR(X->statusbar), 0);
@@ -1045,6 +1045,7 @@
     GError *error;
     GtkWidget *event_box, *view_widget;
     GtkTextBuffer *buffer;
+    GtkWidget *scrolledwindow;
 
     v->tool_label = NULL;
     if (v->titleline == NULL) {
@@ -1099,7 +1100,7 @@
     gtk_box_pack_start(GTK_BOX(X->kvbox), X->menubar, FALSE, FALSE, 0);
 
 
-    GtkWidget *scrolledwindow = gtk_scrolled_window_new(NULL, NULL);
+    scrolledwindow = gtk_scrolled_window_new(NULL, NULL);
     gtk_widget_show(scrolledwindow);
     gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (scrolledwindow), 
 				   GTK_POLICY_ALWAYS, 
