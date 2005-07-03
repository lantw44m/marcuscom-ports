--- battstat/battstat_applet.c.orig	Sun Jul  3 17:25:06 2005
+++ battstat/battstat_applet.c	Sun Jul  3 17:25:36 2005
@@ -446,14 +446,15 @@ battery_full_notify (void)
 static void
 battery_full_dialog( void )
 {
+  GtkWidget *dialog, *hbox, *image, *label;
+  GdkPixbuf *pixbuf;
+  gchar *new_label;
+
   /* first attempt to use libnotify */
   if (battery_full_notify ())
 	  return;
   
-  GtkWidget *dialog, *hbox, *image, *label;
-  GdkPixbuf *pixbuf;
 
-  gchar *new_label;
   dialog = gtk_dialog_new_with_buttons (
 		_("Battery Notice"),
 		NULL,
