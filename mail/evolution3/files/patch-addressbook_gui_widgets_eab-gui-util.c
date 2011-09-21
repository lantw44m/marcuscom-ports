--- addressbook/gui/widgets/eab-gui-util.c.orig	2011-09-16 16:08:49.000000000 +0200
+++ addressbook/gui/widgets/eab-gui-util.c	2011-09-16 16:10:29.000000000 +0200
@@ -655,7 +655,9 @@ get_locales (void)
 	gchar *dot;
 	gchar **split;
 
+#ifdef __linux__
 	locale = g_strdup (setlocale (LC_ADDRESS, NULL));
+#endif
 	if (!locale)
 		return NULL;
 
