--- gnome-about/gnome-about.c.orig	Sun Jun 15 02:04:36 2003
+++ gnome-about/gnome-about.c	Sun Jun 15 02:04:50 2003
@@ -458,9 +458,8 @@
 	g_list_free (files);
 
 	if (error) {
+	    	char * message;
 		g_free (directory);
-
-		char *message;
 
 		message = g_strdup_printf (_("Unable to load header image: %s"),
 					   error->message);
