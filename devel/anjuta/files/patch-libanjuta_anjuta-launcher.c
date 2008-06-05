--- libanjuta/anjuta-launcher.c.orig	2008-05-29 22:37:02.000000000 +0200
+++ libanjuta/anjuta-launcher.c	2008-06-05 16:12:17.000000000 +0200
@@ -67,13 +67,13 @@
 #define FILE_INPUT_BUFFER_SIZE		1048576
 #ifndef __MAX_BAUD
 #  if defined(B460800)
-#    define __MAX_BAUX B460800
+#    define __MAX_BAUD B460800
 #  elif defined(B307200)
-#    define __MAX_BAUX B307200
+#    define __MAX_BAUD B307200
 #  elif defined(B256000)
-#    define __MAX_BAUX B256000
+#    define __MAX_BAUD B256000
 #  else
-#    define __MAX_BAUX B230400
+#    define __MAX_BAUD B230400
 #  endif
 #endif
 
@@ -761,7 +761,8 @@ anjuta_launcher_scan_output (GIOChannel 
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is output */
 			{
 				gchar *utf8_chars = NULL;
@@ -789,6 +790,13 @@ anjuta_launcher_scan_output (GIOChannel 
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
@@ -818,7 +826,8 @@ anjuta_launcher_scan_error (GIOChannel *
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -844,6 +853,13 @@ anjuta_launcher_scan_error (GIOChannel *
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
@@ -873,7 +889,8 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 		GError *err = NULL;
 		do
 		{
-			g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
+			GIOStatus status;
+			status = g_io_channel_read_chars (channel, buffer, FILE_BUFFER_SIZE-1, &n, &err);
 			if (n > 0) /* There is stderr output */
 			{
 				gchar *utf8_chars;
@@ -902,6 +919,10 @@ anjuta_launcher_scan_pty (GIOChannel *ch
 			{
 				ret = FALSE;
 			}
+			else if (status == G_IO_STATUS_EOF)
+			{
+				ret = FALSE;
+			}
 		/* Read next chars if buffer was too small
 		 * (the maximum length of one character is 6 bytes) */
 		} while (!err && (n > FILE_BUFFER_SIZE - 7));
