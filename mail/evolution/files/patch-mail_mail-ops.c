--- mail/mail-ops.c.orig	2010-11-14 14:21:13.000000000 +0100
+++ mail/mail-ops.c	2010-11-14 14:22:02.000000000 +0100
@@ -605,9 +605,9 @@ mail_send_message (struct _send_queue_ms
 				sent_folder_uri, 0, &local_error);
 			if (folder == NULL) {
 				g_string_append_printf (
-					err, _("Failed to append to %s: %s\n"
+					err, _("Failed to append to %s\n"
 					"Appending to local 'Sent' folder instead."),
-					sent_folder_uri, local_error->message);
+					sent_folder_uri);
 				g_clear_error (&local_error);
 			}
 		}
