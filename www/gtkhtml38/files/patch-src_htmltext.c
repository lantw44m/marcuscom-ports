--- src/htmltext.c.orig	Tue Nov 23 15:07:15 2004
+++ src/htmltext.c	Tue Nov 23 15:07:29 2004
@@ -2423,10 +2423,12 @@
 gsize
 html_text_sanitize (const gchar **str, gint *len)
 {
+	gchar *end;
+
 	g_return_val_if_fail (str != NULL, 0);
 	g_return_val_if_fail (len != NULL, 0);
 	
-	gchar *end = offset_to_pointer_validated (*str, *len, len);
+	end = offset_to_pointer_validated (*str, *len, len);
 	if (end) {
 		return end - *str;
 	} else {
