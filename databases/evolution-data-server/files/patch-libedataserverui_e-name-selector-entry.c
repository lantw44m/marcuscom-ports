--- libedataserverui/e-name-selector-entry.c.orig	Wed Jul 13 02:24:07 2005
+++ libedataserverui/e-name-selector-entry.c	Wed Jul 13 02:24:15 2005
@@ -1111,7 +1111,7 @@ user_delete_text (ENameSelectorEntry *na
 {
 	const gchar *text;
 	gint         index_start, index_end;
-	gunichar     str_context [2], str_b_context [2];;
+	gunichar     str_context [2], str_b_context [2];
 	gint         len;
 	gint         i;
 
