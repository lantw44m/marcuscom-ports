--- servers/groupwise/e-gw-item.c.orig	Sat Jul  9 08:01:07 2005
+++ servers/groupwise/e-gw-item.c	Wed Jul 13 02:06:07 2005
@@ -2996,8 +2996,8 @@ e_gw_item_set_calendar_item_elements (EG
 
 	/*attachments*/
 	if (priv->attach_list) {
-		soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 		GSList *al ;
+		soup_soap_message_start_element (msg, "attachments", NULL, NULL) ;
 		for (al = priv->attach_list ; al != NULL ;  al = al->next) {
 			EGwItemAttachment *attachment = (EGwItemAttachment *)al->data ;
 			add_attachment_to_soap_message (attachment, msg) ;
