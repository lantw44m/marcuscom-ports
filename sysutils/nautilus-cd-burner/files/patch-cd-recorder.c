--- cd-recorder.c.orig	Sun Apr 13 03:27:14 2003
+++ cd-recorder.c	Sun Apr 13 03:30:37 2003
@@ -9,10 +9,16 @@
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/uio.h>
+#include <unistd.h>
+#endif
 #include <sys/stat.h>
 #include <sys/ioctl.h>
+#ifndef __FreeBSD__
 #include <scsi/scsi.h>
 #include <scsi/sg.h>
+#endif
 #include <glib.h>
 #include <signal.h>
 #include <libgnome/gnome-i18n.h>
@@ -39,9 +45,9 @@
 	GMainLoop *loop;
 	int result;
 	int pid;
-	int stdin;
+	int cdr_stdin;
 	GString *line;
-	GString *stderr;
+	GString *cdr_stderr;
 	gboolean changed_text;
 	gboolean send_return;
 	gboolean expect_cdrecord_to_die;
@@ -109,7 +115,7 @@
 {
 	if (is_reload) {
 		if (cdrecorder->priv->send_return) {
-			write (cdrecorder->priv->stdin, "\n", 1);
+			write (cdrecorder->priv->cdr_stdin, "\n", 1);
 		} else {
 			kill (cdrecorder->priv->pid, SIGUSR1);
 		}
@@ -214,7 +220,7 @@
 #endif
 	/* TODO: Handle errors */
 	if (status == G_IO_STATUS_NORMAL && !cdrecorder->priv->expect_cdrecord_to_die) {
-		g_string_prepend (cdrecorder->priv->stderr, line);
+		g_string_prepend (cdrecorder->priv->cdr_stderr, line);
 		if (strstr (line, "No disk / Wrong disk!") != NULL) {
 			g_signal_emit (G_OBJECT (cdrecorder),
 				       cd_recorder_table_signals[INSERT_CD_REQUEST], 0,
@@ -277,15 +283,15 @@
 	argv[i++] = filename;
 	argv[i++] = NULL;
 
-	cdrecorder->priv->stderr = NULL;
+	cdrecorder->priv->cdr_stderr = NULL;
  retry:
 	cdrecorder->priv->result = RESULT_ERROR;
 	cdrecorder->priv->expect_cdrecord_to_die = FALSE;
 	cdrecorder->priv->line = NULL;
-	if (cdrecorder->priv->stderr != NULL) {
-		g_string_truncate (cdrecorder->priv->stderr, 0);
+	if (cdrecorder->priv->cdr_stderr != NULL) {
+		g_string_truncate (cdrecorder->priv->cdr_stderr, 0);
 	} else {
-		cdrecorder->priv->stderr = g_string_new (NULL);
+		cdrecorder->priv->cdr_stderr = g_string_new (NULL);
 	}
 
 	g_signal_emit (G_OBJECT (cdrecorder),
@@ -309,7 +315,7 @@
 					G_SPAWN_SEARCH_PATH,
 					NULL, NULL,
 					&cdrecorder->priv->pid,
-					&cdrecorder->priv->stdin,
+					&cdrecorder->priv->cdr_stdin,
 					&stdout_pipe,
 					&stderr_pipe,
 					&error)) {
@@ -374,7 +380,7 @@
 {
 	g_return_val_if_fail (cdrecorder->priv->result != RESULT_ERROR, NULL);
 
-	return (const char *)cdrecorder->priv->stderr->str;
+	return (const char *)cdrecorder->priv->cdr_stderr->str;
 }
 
 const char *
@@ -392,7 +398,7 @@
 
 	g_return_if_fail (object != NULL);
 
-	g_string_free (cdrecorder->priv->stderr, TRUE);
+	g_string_free (cdrecorder->priv->cdr_stderr, TRUE);
 	//FIXME cleanup
 
 	if (G_OBJECT_CLASS (parent_class)->finalize != NULL) {
