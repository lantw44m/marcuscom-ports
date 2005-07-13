--- camel/providers/groupwise/camel-groupwise-folder.c.orig	Wed Jul 13 02:14:43 2005
+++ camel/providers/groupwise/camel-groupwise-folder.c	Wed Jul 13 02:15:18 2005
@@ -947,9 +947,10 @@ gw_update_summary ( CamelFolder *folder,
 		char *temp_date = NULL;
 		const char *id;
 		GSList *recp_list = NULL;
-		status_flags = 0;
 		CamelStream *cache_stream;
 		CamelMimeMessage *mail_msg = NULL;
+
+		status_flags = 0;
 
 		id = e_gw_item_get_id (temp_item);
 
