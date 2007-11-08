--- src/ck-sysdeps-freebsd.c.orig	2007-11-08 15:14:35.000000000 -0500
+++ src/ck-sysdeps-freebsd.c	2007-11-08 15:14:45.000000000 -0500
@@ -202,7 +202,6 @@ ck_process_stat_new_for_unix_pid (pid_t 
                                   GError        **error)
 {
         gboolean       res;
-        GError        *local_error;
         CkProcessStat *proc;
 
         g_return_val_if_fail (pid > 1, FALSE);
@@ -217,7 +216,6 @@ ck_process_stat_new_for_unix_pid (pid_t 
         if (res) {
                 *stat = proc;
         } else {
-                g_propagate_error (error, local_error);
                 *stat = NULL;
         }
 
