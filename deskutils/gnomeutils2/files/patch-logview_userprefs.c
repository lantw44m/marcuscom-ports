--- logview/userprefs.c.orig	Wed Jan 18 18:11:32 2006
+++ logview/userprefs.c	Wed Jan 18 18:06:48 2006
@@ -125,7 +125,7 @@ prefs_load (GConfClient *client)
 	UserPrefs *p;
 	GSList *list;
 	gboolean found;
-    GError *err;
+    GError *err = NULL;
 
     g_assert (client != NULL);
 
