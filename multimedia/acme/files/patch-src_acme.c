--- src/acme.c.orig	Tue Mar 11 20:48:13 2003
+++ src/acme.c	Sun May 25 11:44:56 2003
@@ -198,10 +198,10 @@
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
@@ -1120,7 +1120,7 @@
 		do_www_action (acme, "http://www.gnomedesktop.org");
 		break;
 	case CALCULATOR_KEY:
-		execute ("gnome-calculator", FALSE);
+		execute ("gcalctool", FALSE);
 		break;
 	case RECORD_KEY:
 		execute ("gnome-sound-recorder", FALSE);
