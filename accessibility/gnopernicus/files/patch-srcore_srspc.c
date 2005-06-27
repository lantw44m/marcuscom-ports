--- srcore/srspc.c.orig	Mon Jun 27 20:06:42 2005
+++ srcore/srspc.c	Mon Jun 27 20:06:49 2005
@@ -1535,8 +1535,8 @@
 static void
 src_restart_speech ()
 {
-    g_printerr ("\nRestarting speech.\n");
     gboolean use_speech = FALSE;
+    g_printerr ("\nRestarting speech.\n");
     SET_SRCORE_CONFIG_DATA (SRCORE_SPEECH_ACTIVE, CFGT_BOOL, &use_speech);
     speech_timeout_id = g_timeout_add (SRC_SPEECH_RESTART_TIMEOUT, src_timeout_start_speech, NULL);
 }
@@ -1636,6 +1636,8 @@
 void
 src_speech_terminate ()
 {
+    gboolean use_speech = TRUE;
+
     sru_assert (src_speech_initialized);
 
     src_speech_shutup ();
@@ -1653,7 +1655,6 @@
     g_ptr_array_add (src_created_voices, NULL);
     g_strfreev ((gchar**)g_ptr_array_free (src_created_voices, TRUE));
     
-    gboolean use_speech = TRUE;
     if (speech_timeout_id == 0)
         SET_SRCORE_CONFIG_DATA (SRCORE_SPEECH_ACTIVE, CFGT_BOOL, &use_speech);
 }
