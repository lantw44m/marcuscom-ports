--- Src/Gtk2/dasher_action_speech.cpp.orig	Sun Feb 25 14:07:39 2007
+++ Src/Gtk2/dasher_action_speech.cpp	Sun Feb 25 14:09:45 2007
@@ -108,12 +108,12 @@ dasher_action_speech_execute(DasherActio
 
 static gboolean 
 dasher_action_speech_preview(DasherAction *pSelf, DasherEditor *pEditor) {
-  gchar *szData = dasher_editor_get_all(pEditor);
+  const char *szData = dasher_editor_get_all_text(pEditor);
 
   if(!szData)
     return false;
 
-  gchar *szWord = strrchr(szData, " ") + 1;
+  gchar *szWord = strrchr(szData, ' ') + 1;
 
   DasherActionSpeechPrivate *pDasherActionSpeechPrivate = DASHER_ACTION_SPEECH_GET_PRIVATE(pSelf);
   
