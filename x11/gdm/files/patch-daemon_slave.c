--- daemon/slave.c.orig	2007-07-11 12:51:13.000000000 -0400
+++ daemon/slave.c	2007-07-11 13:05:50.000000000 -0400
@@ -35,6 +35,7 @@
 #include <login_cap.h>
 #endif
 #include <fcntl.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
@@ -45,7 +46,8 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <string.h>
-#include <utmpx.h>
+#include <utmp.h>
+#include <libutil.h>
 
 #if !defined (MAXPATHLEN) && defined (PATH_MAX)
 #define MAXPATHLEN PATH_MAX
@@ -119,7 +121,7 @@
 /* Per-slave globals */
 
 static GdmDisplay *d                   = 0;
-static gchar *login                    = NULL;
+static gchar *gdm_login                    = NULL;
 static gboolean greet                  = FALSE;
 static gboolean configurator           = FALSE;
 static gboolean remanage_asap          = FALSE;
@@ -686,7 +688,7 @@ term_session_stop_and_quit (void)
 	/* only if we're not hanging in session stop and getting a
 	   TERM signal again */
 	if (in_session_stop == 0 && session_started)
-		gdm_slave_session_stop (d->logged_in && login != NULL,
+		gdm_slave_session_stop (d->logged_in && gdm_login != NULL,
 					TRUE /* no_shutdown_check */);
 
 	gdm_debug ("term_session_stop_and_quit: Final cleanup");
@@ -956,11 +958,11 @@ static gboolean
 setup_automatic_session (GdmDisplay *display, const char *name)
 {
 	char *new_login;
-	g_free (login);
-	login = g_strdup (name);
+	g_free (gdm_login);
+	gdm_login = g_strdup (name);
 
 	greet = FALSE;
-	gdm_debug ("setup_automatic_session: Automatic login: %s", login);
+	gdm_debug ("setup_automatic_session: Automatic login: %s", gdm_login);
 
 	/* Run the init script. gdmslave suspends until script
 	 * has terminated */
@@ -970,12 +972,12 @@ setup_automatic_session (GdmDisplay *dis
 	gdm_debug ("setup_automatic_session: DisplayInit script finished");
 
 	new_login = NULL;
-	if ( ! gdm_verify_setup_user (display, login, &new_login))
+	if ( ! gdm_verify_setup_user (display, gdm_login, &new_login))
 		return FALSE;
 
 	if (new_login != NULL) {
-		g_free (login);
-		login = g_strdup (new_login);
+		g_free (gdm_login);
+		gdm_login = g_strdup (new_login);
 	}
 
 	gdm_debug ("setup_automatic_session: Automatic login successful");
@@ -1652,7 +1654,7 @@ gdm_slave_run (GdmDisplay *display)
 				gdm_slave_session_start ();
 			}
 		} else {
-			gdm_slave_send_string (GDM_SOP_LOGIN, login);
+			gdm_slave_send_string (GDM_SOP_LOGIN, gdm_login);
 			gdm_slave_session_start ();
 		}
 
@@ -1982,8 +1984,8 @@ restart_the_greeter (void)
 	gdm_slave_desensitize_config ();
 
 	/* no login */
-	g_free (login);
-	login = NULL;
+	g_free (gdm_login);
+	gdm_login = NULL;
 
 	/* Now restart it */
 	if (greet) {
@@ -2061,11 +2063,11 @@ gdm_slave_wait_for_login (void)
 {
 	const char *successsound;
 	char *username;
-	g_free (login);
-	login = NULL;
+	g_free (gdm_login);
+	gdm_login = NULL;
 
 	/* Chat with greeter */
-	while (login == NULL) {
+	while (gdm_login == NULL) {
 		/* init to a sane value */
 		do_timed_login = FALSE;
 		do_configurator = FALSE;
@@ -2087,21 +2089,21 @@ gdm_slave_wait_for_login (void)
 		gdm_debug ("gdm_slave_wait_for_login: In loop");
 		username = d->preset_user;
 		d->preset_user = NULL;
-		login = gdm_verify_user (d /* the display */,
+		gdm_login = gdm_verify_user (d /* the display */,
 					 username /* username */,
 					 TRUE /* allow retry */);
 		g_free (username);
 
 		gdm_debug ("gdm_slave_wait_for_login: end verify for '%s'",
-			   ve_sure_string (login));
+			   ve_sure_string (gdm_login));
 
 		/* Complex, make sure to always handle the do_configurator
 		 * do_timed_login and do_restart_greeter after any call
 		 * to gdm_verify_user */
 
 		if G_UNLIKELY (do_restart_greeter) {
-			g_free (login);
-			login = NULL;
+			g_free (gdm_login);
+			gdm_login = NULL;
 			do_restart_greeter = FALSE;
 			restart_the_greeter ();
 			continue;
@@ -2114,8 +2116,8 @@ gdm_slave_wait_for_login (void)
 			gboolean oldAllowRoot;
 
 			do_configurator = FALSE;
-			g_free (login);
-			login = NULL;
+			g_free (gdm_login);
+			gdm_login = NULL;
 			/* clear any error */
 			gdm_slave_greeter_ctl_no_ret (GDM_ERRBOX, "");
 			gdm_slave_greeter_ctl_no_ret
@@ -2134,7 +2136,7 @@ gdm_slave_wait_for_login (void)
 			}
 
 			gdm_slave_greeter_ctl_no_ret (GDM_SETLOGIN, pwent->pw_name);
-			login = gdm_verify_user (d,
+			gdm_login = gdm_verify_user (d,
 						 pwent->pw_name,
 						 FALSE);
 			gdm_daemon_config_set_value_bool (GDM_KEY_ALLOW_ROOT, oldAllowRoot);
@@ -2143,8 +2145,8 @@ gdm_slave_wait_for_login (void)
 			gdm_slave_greeter_ctl_no_ret (GDM_MSG, "");
 
 			if G_UNLIKELY (do_restart_greeter) {
-				g_free (login);
-				login = NULL;
+				g_free (gdm_login);
+				gdm_login = NULL;
 				do_restart_greeter = FALSE;
 				restart_the_greeter ();
 				continue;
@@ -2153,15 +2155,15 @@ gdm_slave_wait_for_login (void)
 			check_notifies_now ();
 
 			/* The user can't remember his password */
-			if (login == NULL) {
+			if (gdm_login == NULL) {
 				gdm_debug ("gdm_slave_wait_for_login: No login/Bad login");
 				gdm_slave_greeter_ctl_no_ret (GDM_RESET, "");
 				continue;
 			}
 
 			/* Wipe the login */
-			g_free (login);
-			login = NULL;
+			g_free (gdm_login);
+			gdm_login = NULL;
 
 			/* Note that this can still fall through to
 			 * the timed login if the user doesn't type in the
@@ -2240,7 +2242,7 @@ gdm_slave_wait_for_login (void)
 			break;
 		}
 
-		if (login == NULL) {
+		if (gdm_login == NULL) {
 			const char *failuresound = gdm_daemon_config_get_value_string (GDM_KEY_SOUND_ON_LOGIN_FAILURE_FILE);
 
 			gdm_debug ("gdm_slave_wait_for_login: No login/Bad login");
@@ -2258,8 +2260,8 @@ gdm_slave_wait_for_login (void)
 
 	/* The user timed out into a timed login during the conversation */
 	if (do_timed_login) {
-		g_free (login);
-		login = NULL;
+		g_free (gdm_login);
+		gdm_login = NULL;
 		/* timed login is automatic, thus no need for greeter,
 		 * we'll take default values */
 		gdm_slave_whack_greeter ();
@@ -2269,7 +2271,7 @@ gdm_slave_wait_for_login (void)
 
 	successsound = gdm_daemon_config_get_value_string (GDM_KEY_SOUND_ON_LOGIN_SUCCESS_FILE);
 	/* Play sounds if specified for a successful login */
-	if (login != NULL && successsound &&
+	if (gdm_login != NULL && successsound &&
 	    gdm_daemon_config_get_value_bool (GDM_KEY_SOUND_ON_LOGIN_SUCCESS) &&
 	    d->attached &&
 	    ! play_login_sound (successsound)) {
@@ -2278,7 +2280,7 @@ gdm_slave_wait_for_login (void)
 	}
 
 	gdm_debug ("gdm_slave_wait_for_login: got_login for '%s'",
-		   ve_sure_string (login));
+		   ve_sure_string (gdm_login));
 
 
 }
@@ -3716,7 +3718,7 @@ session_child_run (struct passwd *pwent,
 		gdm_child_exit (DISPLAY_REMANAGE,
 				_("%s: Could not setup environment for %s. "
 				  "Aborting."),
-				"session_child_run", login);
+				"session_child_run", gdm_login);
 
         /* setup euid/egid to the correct user,
          * not to leave the egid around.  It's
@@ -3783,11 +3785,11 @@ session_child_run (struct passwd *pwent,
 		gdm_child_exit (DISPLAY_REMANAGE,
 				_("%s: setusercontext () failed for %s. "
 				  "Aborting."), "session_child_run",
-				login);
+				gdm_login);
 #else
 	if G_UNLIKELY (setuid (pwent->pw_uid) < 0)
 		gdm_child_exit (DISPLAY_REMANAGE,
-				_("%s: Could not become %s. Aborting."), "session_child_run", login);
+				_("%s: Could not become %s. Aborting."), "session_child_run", gdm_login);
 #endif
 
 	/* Only force GDM_LANG to something if there is other then
@@ -3977,7 +3979,7 @@ session_child_run (struct passwd *pwent,
 		failsafe = TRUE;
 	}
 
-	gdm_debug ("Running %s for %s on %s", fullexec->str, login, d->name);
+	gdm_debug ("Running %s for %s on %s", fullexec->str, gdm_login, d->name);
 
 	if ( ! ve_string_empty (pwent->pw_shell)) {
 		shell = pwent->pw_shell;
@@ -4002,7 +4004,7 @@ session_child_run (struct passwd *pwent,
 
 #ifdef CAN_USE_SETPENV
 	/* Call the function setpenv which instanciates the extern variable "newenv" */
-	setpenv (login, (PENV_INIT | PENV_NOEXEC), NULL, NULL);
+	setpenv (gdm_login, (PENV_INIT | PENV_NOEXEC), NULL, NULL);
 
 	/* Add the content of the "newenv" variable to the environment */
 	for (i=0; newenv != NULL && newenv[i] != NULL; i++) {
@@ -4208,8 +4210,8 @@ gdm_slave_write_utmp_wtmp_record (GdmDis
 			const gchar *username,
 			GPid  pid)
 {
-	struct utmpx record = { 0 };
-	struct utmpx *u = NULL;
+	struct utmp record = { 0 };
+	struct utmp *u = NULL;
 	GTimeVal now = { 0 };
 	gchar *device_name = NULL;
 	gchar *host;
@@ -4231,40 +4233,40 @@ gdm_slave_write_utmp_wtmp_record (GdmDis
 		 * username entry to accidently get logged.
 		 */
 		if (username != NULL) {
-			strncpy (record.ut_user,
+			strncpy (record.ut_name,
 				 username, 
-				 sizeof (record.ut_user));
+				 sizeof (record.ut_name));
 		} else {
 			g_assert (record_type == GDM_SESSION_RECORD_TYPE_FAILED_ATTEMPT);
-			strncpy (record.ut_user,
+			strncpy (record.ut_name,
 				 "(unknown)",
-				 sizeof (record.ut_user));
+				 sizeof (record.ut_name));
 		}
 
 		gdm_debug ("utmp-wtmp: Using username %.*s",
-			   sizeof (record.ut_user),
-			   record.ut_user);
+			   sizeof (record.ut_name),
+			   record.ut_name);
 	}
 
 	if (record_type == GDM_SESSION_RECORD_TYPE_LOGOUT) {
-		record.ut_type = DEAD_PROCESS;
+		/*record.ut_type = DEAD_PROCESS;*/
 		gdm_debug ("utmp-wtmp: Using type DEAD_PROCESS"); 
 	} else  {
-		record.ut_type = USER_PROCESS;
+		/*record.ut_type = USER_PROCESS;*/
 		gdm_debug ("utmp-wtmp: Using type USER_PROCESS"); 
 	}
 
-	record.ut_pid = pid;
-	gdm_debug ("utmp-wtmp: Using pid %d", (gint)record.ut_pid);
+	/*record.ut_pid = pid;*/
+	gdm_debug ("utmp-wtmp: Using pid %d", (gint)pid);
 
 	g_get_current_time (&now);
-	record.ut_tv.tv_sec = now.tv_sec;
-	gdm_debug ("utmp-wtmp: Using time %ld", (glong) record.ut_tv.tv_sec);
+	record.ut_time = now.tv_sec;
+	gdm_debug ("utmp-wtmp: Using time %ld", (glong) record.ut_time);
 
-	strncpy (record.ut_id, d->name, sizeof (record.ut_id));
+/*	strncpy (record.ut_id, d->name, sizeof (record.ut_id));
 	gdm_debug ("utmp-wtmp: Using id %.*s",
 	       sizeof (record.ut_id),
-	       record.ut_id);
+	       record.ut_id);*/
 
 	if (device_name != NULL) {
 		g_assert (g_str_has_prefix (device_name, "/dev/"));
@@ -4303,6 +4305,7 @@ gdm_slave_write_utmp_wtmp_record (GdmDis
 	switch (record_type)
 	{
 	case GDM_SESSION_RECORD_TYPE_LOGIN:
+#if 0
 		gdm_debug ("Login utmp/wtmp record");
 		updwtmpx (GDM_NEW_RECORDS_FILE, &record);
 
@@ -4326,11 +4329,15 @@ gdm_slave_write_utmp_wtmp_record (GdmDis
 			gdm_debug ("Adding new utmp record");
 			pututxline (&record);
 		}
+#else
+		login(&record);
+#endif
 
 		break;
 
 	case GDM_SESSION_RECORD_TYPE_LOGOUT: 
 		gdm_debug ("Logout utmp/wtmp record");
+#if 0
 
 		updwtmpx (GDM_NEW_RECORDS_FILE, &record);
 
@@ -4357,12 +4364,15 @@ gdm_slave_write_utmp_wtmp_record (GdmDis
 		}
 
 		endutxent ();
+#else
+		logout(record.ut_line);
+#endif
 		break;
 
 	case GDM_SESSION_RECORD_TYPE_FAILED_ATTEMPT:
 		gdm_debug ("Writing failed session attempt record to " 
 			   GDM_BAD_RECORDS_FILE);
-		updwtmpx (GDM_BAD_RECORDS_FILE, &record);
+		/*updwtmpx (GDM_BAD_RECORDS_FILE, &record);*/
 		break;
 	}
 }
@@ -4391,16 +4401,16 @@ gdm_slave_session_start (void)
 	int logfilefd;
 
 	gdm_debug ("gdm_slave_session_start: Attempting session for user '%s'",
-		   login);
+		   gdm_login);
 
-	pwent = getpwnam (login);
+	pwent = getpwnam (gdm_login);
 
 	if G_UNLIKELY (pwent == NULL)  {
 		/* This is sort of an "assert", this should NEVER happen */
 		if (greet)
 			gdm_slave_whack_greeter ();
 		gdm_slave_exit (DISPLAY_REMANAGE,
-				_("%s: User passed auth but getpwnam (%s) failed!"), "gdm_slave_session_start", login);
+				_("%s: User passed auth but getpwnam (%s) failed!"), "gdm_slave_session_start", gdm_login);
 	}
 
 	logged_in_uid = uid = pwent->pw_uid;
@@ -4408,7 +4418,7 @@ gdm_slave_session_start (void)
 
 	/* Run the PostLogin script */
 	if G_UNLIKELY (gdm_slave_exec_script (d, gdm_daemon_config_get_value_string (GDM_KEY_POSTLOGIN),
-					      login, pwent,
+					      gdm_login, pwent,
 					      TRUE /* pass_stdout */) != EXIT_SUCCESS &&
 		       /* ignore errors in failsafe modes */
 		       ! failsafe) {
@@ -4448,7 +4458,7 @@ gdm_slave_session_start (void)
 
 		gdm_error (_("%s: Home directory for %s: '%s' does not exist!"),
 			   "gdm_slave_session_start",
-			   login,
+			   gdm_login,
 			   ve_sure_string (pwent->pw_dir));
 
 		/* Check what the user wants to do */
@@ -4900,8 +4910,8 @@ gdm_slave_session_stop (gboolean run_pos
 
 	session_started = FALSE;
 
-	local_login = login;
-	login = NULL;
+	local_login = gdm_login;
+	gdm_login = NULL;
 
 	/* don't use NEVER_FAILS_ here this can be called from places
 	   kind of exiting and it's ok if this doesn't work (when shouldn't
