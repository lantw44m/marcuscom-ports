--- mail/em-junk-filter.c.orig	Mon Jan 12 16:21:24 2004
+++ mail/em-junk-filter.c	Tue Jan 13 14:00:48 2004
@@ -176,7 +176,7 @@
 	int retval;
 
 	d(fprintf (stderr, "test if spamd is running (port %d)\n", port);)
-	sac_args [2] = port > 0  ? g_strdup_printf ("spamc -x -p %d", port) : g_strdup_printf ("spamc -x");
+	sac_args [2] = port > 0  ? g_strdup_printf ("'spamc -x -p %d'", port) : g_strdup_printf ("'spamc -x'");
 
 	retval = pipe_to_sa (NULL, "From test@127.0.0.1", 3, sac_args) == 0;
 	g_free (sac_args [2]);
@@ -191,7 +191,7 @@
 	static gchar *args [4] = {
 		"/bin/sh",
 		"-c",
-		"spamassassin --version",
+		"'spamassassin --version'",
 		NULL
 	};
 
@@ -229,7 +229,7 @@
 				for (i = 0; i < NPORTS; i ++) {
 					d(fprintf (stderr, "trying to run spamd at port %d\n", port));
 
-					sad_args [2] = g_strdup_printf ("spamd --port %d %s--daemonize", port, mail_session_get_sa_local_only () ? "--local " : "");
+					sad_args [2] = g_strdup_printf ("'spamd --port %d %s--daemonize'", port, mail_session_get_sa_local_only () ? "--local " : "");
 					if (!pipe_to_sa (NULL, NULL, 3, sad_args)) {
 						g_free (sad_args [2]);
 						em_junk_sa_use_spamc = TRUE;
@@ -277,14 +277,14 @@
 
 	args [2] = (em_junk_sa_use_spamc && mail_session_get_sa_use_daemon ())
 		? (em_junk_sa_spamd_port == -1
-		   ? g_strdup ("spamc -c")         /* Exit with a non-zero exit code if the
+		   ? g_strdup ("'spamc -c'")         /* Exit with a non-zero exit code if the
 						      tested message was junk */
-		   : g_strdup_printf ("spamc"
+		   : g_strdup_printf ("'spamc"
 				      " -c"        /* Exit with a non-zero exit code if the
 						      tested message was junk */
-				      " -p %d", em_junk_sa_spamd_port))
-		: g_strdup_printf ("spamassassin"
-				   " --exit-code%s",                  /* Exit with a non-zero exit code if the
+				      " -p %d'", em_junk_sa_spamd_port))
+		: g_strdup_printf ("'spamassassin"
+				   " --exit-code%s'",                  /* Exit with a non-zero exit code if the
 									 tested message was junk */
 				   mail_session_get_sa_local_only ()
 				   ? " --local" : "");                /* Local tests only (no online tests) */
@@ -310,10 +310,10 @@
 
 	if (em_junk_sa_is_available ()) {
 		args [2] = g_strdup_printf 
-			("sa-learn"
+			("'sa-learn"
 			 " --no-rebuild"        /* do not rebuild db */
 			 " --spam"              /* report junk */
-			 " --single%s",         /* single message */
+			 " --single%s'",         /* single message */
 			 mail_session_get_sa_local_only ()
 			 ? " --local" : "");    /* local only */
 		pipe_to_sa (msg, NULL, 3, args);
@@ -335,10 +335,10 @@
 
 	if (em_junk_sa_is_available ()) {
 		args [2] = g_strdup_printf
-			("sa-learn"
+			("'sa-learn"
 			 " --no-rebuild"        /* do not rebuild db */
 			 " --ham"               /* report notjunk */
-			 " --single%s",         /* single message */
+			 " --single%s'",         /* single message */
 			 mail_session_get_sa_local_only ()
 			 ? " --local" : "");    /* local only */
 		pipe_to_sa (msg, NULL, 3, args);
@@ -360,8 +360,8 @@
 
 	if (em_junk_sa_is_available ()) {
 		args [2] = g_strdup_printf
-			("sa-learn"
-			 " --rebuild%s",           /* do not rebuild db */
+			("'sa-learn"
+			 " --rebuild%s'",           /* do not rebuild db */
 			 mail_session_get_sa_local_only ()
 			 ? " --local" : "");       /* local only */
 		pipe_to_sa (NULL, NULL, 3, args);
