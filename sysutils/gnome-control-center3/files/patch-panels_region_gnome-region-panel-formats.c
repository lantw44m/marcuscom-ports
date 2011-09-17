--- panels/region/gnome-region-panel-formats.c.orig	2011-09-17 14:42:28.000000000 +0200
+++ panels/region/gnome-region-panel-formats.c	2011-09-17 14:46:49.000000000 +0200
@@ -131,6 +131,8 @@ update_examples_cb (GtkTreeSelection *se
 	setlocale (LC_MONETARY, locale);
 	g_free (locale);
 
+// FreeBSD doesn't have LC_MEASUREMENT (yet)
+#if 0
 	/* Display measurement */
 	locale = g_strdup (setlocale (LC_MEASUREMENT, NULL));
 	setlocale (LC_MEASUREMENT, active_id);
@@ -143,6 +145,7 @@ update_examples_cb (GtkTreeSelection *se
 
 	setlocale (LC_MEASUREMENT, locale);
 	g_free (locale);
+#endif
         g_free (active_id);
 }
 
