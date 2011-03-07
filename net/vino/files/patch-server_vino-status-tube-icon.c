--- server/vino-status-tube-icon.c.orig	2011-03-07 09:46:02.000000000 +0100
+++ server/vino-status-tube-icon.c	2011-03-07 09:46:32.000000000 +0100
@@ -405,8 +405,7 @@ vino_status_tube_icon_show_notif (VinoSt
       filename = "stock_person";
 
   icon->priv->new_client_notification =
-      notify_notification_new_with_status_icon (summary, body,
-      filename, GTK_STATUS_ICON (icon));
+      notify_notification_new (summary, body, filename);
 
   notify_notification_set_timeout (icon->priv->new_client_notification,
       NOTIFICATION_TIMEOUT * 1000);
