--- mail/em-junk-filter.c.orig	Thu Nov 13 19:33:26 2003
+++ mail/em-junk-filter.c	Fri Jan  9 15:49:44 2004
@@ -189,7 +189,7 @@
 	static gchar *args [3] = {
 		"/bin/sh",
 		"-c",
-		"spamassassin --version"
+		"'spamassassin --version'" /* quoted command string */
 	};
 
 	if (pipe_to_sa (NULL, NULL, 3, args))
@@ -225,7 +225,7 @@
 				for (i = 0; i < NPORTS; i ++) {
 					d(fprintf (stderr, "trying to run spamd at port %d\n", port));
 
-					sad_args [2] = g_strdup_printf ("spamd --port %d --local --daemonize", port);
+					sad_args [2] = g_strdup_printf ("'spamd --port %d --local --daemonize'", port); /* quote command string */
 					if (!pipe_to_sa (NULL, NULL, 3, sad_args)) {
 						g_free (sad_args [2]);
 						em_junk_sa_use_spamc = TRUE;
@@ -274,15 +274,17 @@
 		? (em_junk_sa_spamd_port == -1
 		   ? g_strdup ("spamc -c")         /* Exit with a non-zero exit code if the
 						      tested message was junk */
-		   : g_strdup_printf ("spamc"
+		   : g_strdup_printf ("'"
+                      "spamc"
 				      " -c"        /* Exit with a non-zero exit code if the
 						      tested message was junk */
 				      " -p %d", em_junk_sa_spamd_port))
 		: g_strdup ("spamassassin"
 			    " --exit-code"         /* Exit with a non-zero exit code if the
 						      tested message was junk */
-			    " --local");           /* Local tests only (no online tests) */
-
+			    " --local"  /* Local tests only (no online tests) */
+                "'" 
+                );           
 	retval = pipe_to_sa (msg, NULL, 3, args);
 
 	g_free (args [2]);
@@ -296,11 +298,13 @@
 	static gchar *args [3] = {
 		"/bin/sh",
 		"-c",
+        "'"                    /* begin quote */
 		"sa-learn"
 		" --no-rebuild"        /* do not rebuild db */
 		" --spam"              /* report junk */
 		" --single"            /* single message */
 		" --local"             /* local only */
+        "'"                    /* end quote */
 	};
 
 	d(fprintf (stderr, "em_junk_sa_report_junk\n"));
@@ -315,11 +319,13 @@
 	static gchar *args [3] = {
 		"/bin/sh",
 		"-c",
+        "'"                    /* begin quote */
 		"sa-learn"
 		" --no-rebuild"        /* do not rebuild db */
 		" --ham"               /* report notjunk */
 		" --single"            /* single message */
 		" --local"             /* local only */
+        "'"                    /* end quote */
 	};
 
 	d(fprintf (stderr, "em_junk_sa_report_notjunk\n"));
@@ -334,9 +340,11 @@
 	static gchar *args [3] = {
 		"/bin/sh",
 		"-c",
+        "'"                    /* begin quote */
 		"sa-learn"
 		" --rebuild"           /* do not rebuild db */
 		" --local"             /* local only */
+        "'"                    /* end quote */
 	};
 
 	d(fprintf (stderr, "em_junk_sa_commit_reports\n");)
