--- src/acme.c.orig	Mon Jan 27 17:58:12 2003
+++ src/acme.c	Mon Jan 27 17:58:42 2003
@@ -201,10 +201,10 @@
 	if ((soundfile == NULL) || (strcmp (soundfile, "") == 0)) 
 		return;
 
-	if (g_file_test ("/usr/bin/esdplay",
+	if (g_file_test ("/usr/local/bin/esdplay",
 			(G_FILE_TEST_EXISTS | G_FILE_TEST_IS_EXECUTABLE)))
 	{
-		command = g_strdup_printf ("/usr/bin/esdplay %s",
+		command = g_strdup_printf ("/usr/local/bin/esdplay %s",
 				soundfile);
 	} else if (g_file_test ("/usr/bin/play",
 			(G_FILE_TEST_EXISTS | G_FILE_TEST_IS_EXECUTABLE)))
