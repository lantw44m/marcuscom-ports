--- camel/providers/groupwise/camel-groupwise-folder.c.orig	Mon Aug  8 05:12:44 2005
+++ camel/providers/groupwise/camel-groupwise-folder.c	Mon Aug  8 20:42:33 2005
@@ -929,10 +929,11 @@ gw_update_cache ( CamelFolder *folder, G
 		char *temp_date = NULL;
 		const char *id;
 		GSList *recp_list = NULL;
-		status_flags = 0;
 		CamelStream *cache_stream;
 		CamelMimeMessage *mail_msg = NULL;
 
+		status_flags = 0;
+
 		id = e_gw_item_get_id (temp_item);
 
 		cache_stream  = camel_data_cache_get (gw_folder->cache, "cache", id, ex);
@@ -1609,6 +1610,7 @@ groupwise_transfer_messages_to (CamelFol
 			const char *old_uid = (const char*)uids->pdata[index];
 			char **tmp;
 			guint32 temp_flags = 0;
+			CamelGroupwiseMessageInfo *dest_info;
 			CamelGroupwiseMessageInfo *src_info = (CamelGroupwiseMessageInfo *)camel_folder_summary_uid (source->summary, (const char*)uids->pdata[index]);
 			
 			/* we don't want to blindly copy the info: reset some flags not suitable for destination*/
@@ -1617,7 +1619,7 @@ groupwise_transfer_messages_to (CamelFol
 			else if (!strcmp(destination->full_name, JUNK_FOLDER))
 				camel_folder_set_message_flags (source, old_uid, CAMEL_MESSAGE_JUNK, CAMEL_GW_MESSAGE_JUNK);
 
-			CamelGroupwiseMessageInfo *dest_info = (CamelGroupwiseMessageInfo *)camel_message_info_clone((CamelMessageInfo *)src_info);
+			dest_info = (CamelGroupwiseMessageInfo *)camel_message_info_clone((CamelMessageInfo *)src_info);
 			tmp = g_strsplit (old_uid, ":", -1);
 			dest_info->info.uid = g_strdup_printf ("%s:%s",tmp[0], dest_container_id);
 			temp_flags = camel_folder_get_message_flags (source, (const char *)uids->pdata[index]);
