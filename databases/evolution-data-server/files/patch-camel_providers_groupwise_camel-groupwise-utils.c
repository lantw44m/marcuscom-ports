--- camel/providers/groupwise/camel-groupwise-utils.c.orig	Wed Jul 13 02:16:06 2005
+++ camel/providers/groupwise/camel-groupwise-utils.c	Wed Jul 13 02:16:19 2005
@@ -383,9 +383,10 @@ camel_groupwise_util_item_from_message (
 				attachment->contentType = g_strdup_printf ("%s/%s", type->type, type->subtype) ;
 				if (!g_ascii_strncasecmp (attachment->contentType, RFC_822, strlen (RFC_822))) {
 					char *temp_id = NULL, *id = NULL;
+					int len;
 					//id = (char *)camel_mime_message_get_message_id ((CamelMimeMessage *)dw);
 					temp_id = (char *)camel_medium_get_header (CAMEL_MEDIUM ((CamelMimeMessage *)dw), "Message-Id");
-					int len = strlen (temp_id);
+					len = strlen (temp_id);
 
 					id = (char *)g_malloc0 (len-1);
 					id = memcpy(id, temp_id+2, len-3);
