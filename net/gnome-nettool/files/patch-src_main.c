--- src/main.c.orig	2009-03-21 15:21:51.000000000 -0400
+++ src/main.c	2009-03-21 15:22:02.000000000 -0400
@@ -120,6 +120,8 @@ main (int argc, char *argv[])
 	textdomain (GETTEXT_PACKAGE);
 #endif
 
+	glibtop_init ();
+
 	if (!gtk_init_with_args (&argc, &argv, NULL, options, NULL, &error)) {
 		g_print ("%s\n\n", error->message);
 		return -1;
@@ -228,8 +230,6 @@ main (int argc, char *argv[])
 
 	gtk_widget_show (window);
 
-	glibtop_init ();
-
 	gtk_main ();
 
 	glibtop_close ();
