--- gok/gok-spy.c.orig	Fri Nov 14 13:24:02 2003
+++ gok/gok-spy.c	Fri Nov 14 13:25:09 2003
@@ -1246,8 +1246,9 @@
 				if ( len != 0 )  {
 					if (len > 18) 
 					{
+					    gchar *tmp;
 						gok_log("shortening description");
-						gchar *tmp = g_strndup (s, 15);
+						tmp = g_strndup (s, 15);
 						pName = g_strconcat (tmp, "...", NULL);
 						g_free (tmp);
 					}
@@ -1273,6 +1274,9 @@
 		}
 		*/
 		else if (Accessible_isText (pAccessible)) {
+		    	AccessibleText *text;
+			gint j = 0, len;
+			char *word, *gs = NULL;
 			gok_log("still no name, but there is text...");
 			/* 
 			* sadly, many text objects are still nameless - yet we want 
@@ -1281,9 +1285,7 @@
 			* empty, then we can still "create" a name for it, though we 
 			* can't assign it a unique meaningful name.
 			*/
-			AccessibleText *text = Accessible_getText (pAccessible);
-			gint j = 0, len;
-			gchar *word, *gs = NULL;
+			text = Accessible_getText (pAccessible);
 			if (text) {
 				long int start, end = 0;
 				do {
