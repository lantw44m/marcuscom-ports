--- gnome-screenshot/screenshot-save.c.orig	Fri Dec 17 01:34:33 2004
+++ gnome-screenshot/screenshot-save.c	Fri Dec 17 01:34:40 2004
@@ -89,7 +89,7 @@
 		      GIOCondition  condition,
 		      gpointer      data)
 {
-  if (condition & G_IO_IN)
+  if (!condition & G_IO_IN)
     {
       gchar *message = NULL;
       gchar *error_message = NULL;
