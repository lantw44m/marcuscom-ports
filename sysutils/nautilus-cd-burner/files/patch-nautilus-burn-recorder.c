--- nautilus-burn-recorder.c.orig	Tue May 17 17:12:38 2005
+++ nautilus-burn-recorder.c	Tue May 17 17:13:21 2005
@@ -69,7 +69,7 @@ struct _NautilusBurnProcess {
 	GString                  *line_stderr;
 	NautilusBurnProcessFuncs *funcs;
 
-	int                       stdin;
+	int                       nbp_stdin;
 
 	time_t                    start_time;
 	gint64                    start_num;
@@ -308,7 +308,7 @@ insert_cd_retry (NautilusBurnProcess *pr
 		nautilus_burn_process_cancel (process, FALSE);
 	} else if (is_reload) {
 		if (send_return) {
-			write (process->stdin, "\n", 1);
+			write (process->nbp_stdin, "\n", 1);
 		} else {
 			kill (process->pid, SIGUSR1);
 		}
@@ -1244,7 +1244,7 @@ nautilus_burn_recorder_run_process (Naut
 				      recorder,
 				      &stdout_tag,
 				      &stderr_tag,
-				      &process->stdin,
+				      &process->nbp_stdin,
 				      &local_error);
 
 	if (! res) {
