--- server/vino-status-icon.c.orig	2011-03-07 09:37:18.000000000 +0100
+++ server/vino-status-icon.c	2011-03-07 09:45:10.000000000 +0100
@@ -622,10 +622,9 @@ vino_status_icon_show_new_client_notific
     }
 
   icon->priv->new_client_notification =
-    notify_notification_new_with_status_icon (summary,
-                                              body,
-                                              "preferences-desktop-remote-desktop",
-                                              GTK_STATUS_ICON (icon));
+    notify_notification_new (summary,
+                             body,
+                             "preferences-desktop-remote-desktop");
 
   g_free (body);
 
