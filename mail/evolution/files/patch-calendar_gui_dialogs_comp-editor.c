--- calendar/gui/dialogs/comp-editor.c.orig	Tue Aug 23 16:06:26 2005
+++ calendar/gui/dialogs/comp-editor.c	Tue Aug 23 16:06:46 2005
@@ -2027,7 +2027,7 @@ set_attachment_list (CompEditor *editor,
 		CamelDataWrapper *wrapper;
 		CamelStream *stream;
 		struct stat statbuf;
-		char *mime_type, *file_name;		
+		char *mime_type, *file_name, *ptr;		
 
 		attach_filename = (char *) p->data;
 		/* should we assert if g_str_has_prefix (attach_filename, "file://")) 
@@ -2079,7 +2079,7 @@ set_attachment_list (CompEditor *editor,
 	
 		camel_mime_part_set_disposition (part, "attachment");
 
-		char *ptr = strstr (attach_filename, comp_uid);
+		ptr = strstr (attach_filename, comp_uid);
 		if (ptr) {
 			ptr += strlen(comp_uid);
 			if (*ptr++ == '-')
