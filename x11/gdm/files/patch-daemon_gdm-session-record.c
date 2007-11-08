--- daemon/gdm-session-record.c.orig	2007-10-30 14:54:03.000000000 -0400
+++ daemon/gdm-session-record.c	2007-11-08 15:29:41.000000000 -0500
@@ -85,7 +85,7 @@ record_set_username (UTMP       *u,
                  u->ut_user);
 #elif defined(HAVE_UT_UT_NAME)
         strncpy (u->ut_name,
-                 username
+                 username,
                  sizeof (u->ut_name));
         g_debug ("using ut_name %.*s",
                  (int) sizeof (u->ut_name),
@@ -228,7 +228,7 @@ gdm_session_record_login (GPid          
         updwtmpx (GDM_NEW_SESSION_RECORDS_FILE, &session_record);
 #elif defined(HAVE_UPDWTMP)
         updwtmp (GDM_NEW_SESSION_RECORDS_FILE, &session_record);
-#elif defined(HAVE_LOGWTMP) && defined(HAVE_UT_UT_HOST) && !defined(HAVE_LOGIN)
+#elif defined(HAVE_LOGWTMP) && defined(HAVE_UT_UT_HOST)
 #if defined(HAVE_UT_UT_USER)
         logwtmp (session_record.ut_line, session_record.ut_user, session_record.ut_host);
 #elif defined(HAVE_UT_UT_NAME)
@@ -261,6 +261,8 @@ gdm_session_record_login (GPid          
                 g_debug ("Adding new utmp record");
                 pututxline (&session_record);
         }
+#elif defined(HAVE_LOGIN)
+	login (&session_record);
 #endif
 }
 
@@ -296,7 +298,7 @@ gdm_session_record_logout (GPid         
 #elif defined (HAVE_UPDWTMP)
         updwtmp (GDM_NEW_SESSION_RECORDS_FILE, &session_record);
 #elif defined(HAVE_LOGWTMP)
-        logwtmp (record.ut_line, "", "");
+        logwtmp (session_record.ut_line, "", "");
 #endif
 
         /* Handle utmp */
