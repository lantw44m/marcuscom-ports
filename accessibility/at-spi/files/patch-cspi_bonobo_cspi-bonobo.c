--- cspi/bonobo/cspi-bonobo.c.orig	Mon Aug 30 16:27:46 2004
+++ cspi/bonobo/cspi-bonobo.c	Mon Aug 30 16:28:04 2004
@@ -96,9 +96,10 @@
 		canonical_display_name = ":0";
 	    else
 	    {
+		gchar *display_p, *screen_p;
 		canonical_display_name = g_strdup (display_env);
-		gchar *display_p = strrchr (canonical_display_name, ':');
-		gchar *screen_p = strrchr (canonical_display_name, '.');
+		display_p = strrchr (canonical_display_name, ':');
+		screen_p = strrchr (canonical_display_name, '.');
 		if (screen_p && display_p && ((guint) screen_p > (guint) display_p))
 		{
 		    *screen_p = '\0';
