--- gok/gok-keyboard.c.orig	Sat Oct  9 10:49:42 2004
+++ gok/gok-keyboard.c	Sat Oct  9 10:50:38 2004
@@ -3950,9 +3950,9 @@
 	GokOutput    delim_output;
 	GokKeyboard* pPredictedKeyboard;
 	GokKeyboard* pKeyboardTemp;
-	GokKeyboard* keyboard = gok_main_get_current_keyboard ();
 	GokKey* pKeyTemp;
 	const gchar *str;
+	keyboard = gok_main_get_current_keyboard ();
 	
 	gok_log_enter();
 
