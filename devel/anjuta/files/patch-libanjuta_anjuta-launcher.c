--- libanjuta/anjuta-launcher.c.orig	2008-01-06 18:26:38.000000000 +0100
+++ libanjuta/anjuta-launcher.c	2008-01-13 14:47:16.000000000 +0100
@@ -37,7 +37,7 @@
 #include <signal.h>
 
 #if !defined(__sun) && !defined(__NetBSD__)
-#  ifndef FREEBSD
+#  if !defined(__FreeBSD__)
 #    include <pty.h>
 #  else
 #    include <libutil.h>
@@ -745,7 +745,8 @@
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0 && !err) /* There is output */
 			{
 				gchar *utf8_chars;
@@ -772,6 +773,13 @@
 				anjuta_launcher_synchronize (launcher);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				launcher->priv->stdout_is_done = TRUE;
+				anjuta_launcher_synchronize (launcher);
+				ret = FALSE;
+			}
+
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
@@ -801,7 +809,8 @@
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0 && !err) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -829,6 +838,13 @@
 				anjuta_launcher_synchronize (launcher);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				launcher->priv->stderr_is_done = TRUE;
+				anjuta_launcher_synchronize (launcher);
+				ret = FALSE;
+			}
+
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
@@ -858,7 +874,8 @@
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0 && !err) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -889,6 +906,10 @@
 				DEBUG_PRINT ("pty: %s", err->message);
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				ret = FALSE;
+			}
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
