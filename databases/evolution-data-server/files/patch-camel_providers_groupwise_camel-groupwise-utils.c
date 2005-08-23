--- camel/providers/groupwise/camel-groupwise-utils.c.orig	Fri Aug 19 08:56:58 2005
+++ camel/providers/groupwise/camel-groupwise-utils.c	Tue Aug 23 13:14:06 2005
@@ -333,8 +333,9 @@ send_as_attachment (EGwConnection *cnc, 
 	attachment->name = g_strdup (filename ? filename : "");
 	if (!g_ascii_strncasecmp (attachment->contentType, RFC_822, strlen (RFC_822))) {
 		char *temp_id = NULL, *id = NULL;
+		int len;
 		temp_id = (char *)camel_medium_get_header (CAMEL_MEDIUM ((CamelMimeMessage *)dw), "Message-Id");
-		int len = strlen (temp_id);
+		len = strlen (temp_id);
 
 		id = (char *)g_malloc0 (len-1);
 		id = memcpy(id, temp_id+2, len-3);
