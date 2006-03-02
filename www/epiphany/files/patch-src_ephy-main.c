--- src/ephy-main.c.orig	Wed Mar  1 16:34:13 2006
+++ src/ephy-main.c	Wed Mar  1 16:34:15 2006
@@ -569,14 +569,13 @@ main (int argc,
 
 		for (i = 0; arguments[i] != NULL; ++i)
 		{
-			char *uri, *path = NULL;
+			char *uri, *path = NULL, rpath[PATH_MAX];
 
-			path = realpath (arguments[i], NULL);
+			path = realpath (arguments[i], rpath);
 			if (path != NULL)
 			{
 				uri = g_locale_to_utf8 (path, -1, 
 							NULL, NULL, &error);
-				free (path);
 			}
 			else
 			{
