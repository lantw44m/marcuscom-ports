--- camel/providers/groupwise/camel-groupwise-folder.c.orig	Thu Apr 28 23:03:18 2005
+++ camel/providers/groupwise/camel-groupwise-folder.c	Thu Apr 28 23:06:04 2005
@@ -99,6 +99,7 @@ groupwise_folder_get_message( CamelFolde
 	char *dtstring = NULL;
 	CamelStream *stream, *cache_stream;
 	CamelMultipart *multipart ;
+	CamelMimePart *part ;
 	int errno;
 	struct _camel_header_address *ha;
 	char *subs_email;
@@ -304,7 +305,6 @@ groupwise_folder_get_message( CamelFolde
 	/*Content and content-type*/
 
 	body = g_strdup(e_gw_item_get_message(item));
-	CamelMimePart *part ;
 	part = camel_mime_part_new () ;
 	camel_multipart_set_boundary (multipart, NULL);
 	camel_mime_part_set_encoding(part, CAMEL_TRANSFER_ENCODING_8BIT);
