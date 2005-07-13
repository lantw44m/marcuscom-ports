--- calendar/gui/gnome-cal.c.orig	Wed Jul 13 03:25:16 2005
+++ calendar/gui/gnome-cal.c	Wed Jul 13 03:25:38 2005
@@ -3409,8 +3409,9 @@ gnome_calendar_edit_appointment (GnomeCa
 		return;
 	
 	for (l = gcal->priv->clients_list[E_CAL_SOURCE_TYPE_EVENT]; l != NULL; l = l->next) {
+		ESource *client_src;
 		client = l->data;
-		ESource *client_src = e_cal_get_source (client);
+		client_src = e_cal_get_source (client);
 
 		if (!strcmp (src_uid, e_source_peek_uid (client_src)))
 			break;
