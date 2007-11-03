--- daemon/gdm-session-record.c.orig	2007-11-02 20:51:29.000000000 -0400
+++ daemon/gdm-session-record.c	2007-11-02 20:52:49.000000000 -0400
@@ -85,7 +85,7 @@ record_set_username (UTMP       *u,
                  u->ut_user);
 #elif defined(HAVE_UT_UT_NAME)
         strncpy (u->ut_name,
-                 username
+                 username,
                  sizeof (u->ut_name));
         g_debug ("using ut_name %.*s",
                  (int) sizeof (u->ut_name),
@@ -296,7 +296,7 @@ gdm_session_record_logout (GPid         
 #elif defined (HAVE_UPDWTMP)
         updwtmp (GDM_NEW_SESSION_RECORDS_FILE, &session_record);
 #elif defined(HAVE_LOGWTMP)
-        logwtmp (record.ut_line, "", "");
+        logwtmp (session_record.ut_line, "", "");
 #endif
 
         /* Handle utmp */
