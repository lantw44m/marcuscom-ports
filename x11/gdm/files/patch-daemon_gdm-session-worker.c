--- daemon/gdm-session-worker.c.orig        2008-07-30 19:15:47.000000000 -0400
+++ daemon/gdm-session-worker.c        2008-08-25 12:50:00.000000000 -0400
@@ -332,7 +332,7 @@ gdm_session_execute (const char *file,
                          * what to search if PATH is unset. POSIX may, dunno.
                          */
 
-                        path = "/bin:/usr/bin:.";
+                        path = "/bin:/usr/bin:/usr/local/bin:.";
                 }
 
                 len = strlen (file) + 1;
@@ -1062,6 +1062,10 @@ gdm_session_worker_initialize_pam (GdmSe
         pam_conversation.conv = (GdmSessionWorkerPamNewMessagesFunc) gdm_session_worker_pam_new_messages_handler;
         pam_conversation.appdata_ptr = worker;
 
+        g_setenv ("DISPLAY", x11_display_name, FALSE);
+
+        g_setenv ("XAUTHORITY", x11_authority_file, FALSE);
+
         gdm_session_worker_start_auditor (worker);
         error_code = pam_start (service,
                                 username,
