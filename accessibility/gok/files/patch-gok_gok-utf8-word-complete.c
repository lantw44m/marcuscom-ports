--- gok/gok-utf8-word-complete.c.orig	Mon Mar  1 17:27:56 2004
+++ gok/gok-utf8-word-complete.c	Mon Mar  1 17:28:25 2004
@@ -323,11 +323,11 @@
 		{
 			/* reallocate string, dup+concat substrings */
 			/* WARNING: horrible pointer math */
-			gok_log ("caution: relocating input string during case conversion.");
 			gint delta = newlen - len;
 			gchar *next_char = g_utf8_find_next_char (*utf8char, NULL);
 			guint offset = next_char - *word;
 			guint utf8_offset = (guint) (*utf8char - *word);
+			gok_log ("caution: relocating input string during case conversion.");
 
 			*word = g_realloc (*word, strlen (*word) + 1 + delta);
 			next_char = *word + offset;
