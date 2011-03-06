--- src/gpk-watch.c.orig	2011-03-06 21:37:54.000000000 +0100
+++ src/gpk-watch.c	2011-03-06 21:41:39.000000000 +0100
@@ -1153,7 +1153,7 @@ gpk_watch_process_messages_cb (PkMessage
 	}
 
 	/* do the bubble */
-	notification = notify_notification_new_with_status_icon (gpk_message_enum_to_localised_text (type), details, "emblem-important", watch->priv->status_icon);
+	notification = notify_notification_new (gpk_message_enum_to_localised_text (type), details, "emblem-important");
 	notify_notification_set_timeout (notification, NOTIFY_EXPIRES_NEVER);
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_LOW);
 	ret = notify_notification_show (notification, &error);
