--- src/notification/libnotify.c.orig	2011-03-07 11:14:15.000000000 +0100
+++ src/notification/libnotify.c	2011-03-07 11:14:29.000000000 +0100
@@ -150,7 +150,7 @@ static void notif_libnotify_callback_sho
 //		notify_notification_update ( n, node_get_title(node_p), labelText_now_p, NULL);
 //		notify_notification_clear_actions(n);
 
-		n = notify_notification_new (node_get_title(node_p), labelText_now_p, NULL, NULL);
+		n = notify_notification_new (node_get_title(node_p), labelText_now_p, NULL);
 
 		notify_notification_set_icon_from_pixbuf (n,node_get_icon(node_p));
 
@@ -244,7 +244,7 @@ notif_libnotify_node_has_new_items (node
 
 	labelSummary_p = g_strdup_printf (ngettext ("%s has %d new / updated headline\n", "%s has %d new / updated headlines\n", item_count), 
 	                                  node_get_title (node), item_count);
-	n = notify_notification_new ( _("Feed Update"), labelSummary_p, NULL, NULL);
+	n = notify_notification_new ( _("Feed Update"), labelSummary_p, NULL);
 	g_free(labelSummary_p);
 
 	notify_notification_set_icon_from_pixbuf (n, node_get_icon (node));
