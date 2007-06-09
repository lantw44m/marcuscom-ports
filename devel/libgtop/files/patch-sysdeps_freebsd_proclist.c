--- sysdeps/freebsd/proclist.c.orig	Fri Jun  8 19:46:18 2007
+++ sysdeps/freebsd/proclist.c	Fri Jun  8 19:48:47 2007
@@ -40,7 +40,7 @@ static const unsigned long _glibtop_sysd
  * buf->flags is only set if the call succeeded, in this case pids_chain,
  * a list of the pids of all currently running processes is returned,
  * buf->number is the number of elements of this list and buf->size is
- * the size of one single element (sizeof (unsigned)). The total size is
+ * the size of one single element (sizeof (pid_t)). The total size is
  * stored in buf->total.
  *
  * The calling function has to free the memory to which a pointer is returned.
@@ -61,7 +61,7 @@ _glibtop_init_proclist_p (glibtop *serve
 	server->sysdeps.proclist = _glibtop_sysdeps_proclist;
 }
 
-unsigned *
+pid_t *
 glibtop_get_proclist_p (glibtop *server, glibtop_proclist *buf,
 			gint64 which, gint64 arg)
 {
@@ -90,18 +90,18 @@ glibtop_get_proclist_p (glibtop *server,
 
 	len /= sizeof (struct kinfo_proc);
 
-	pids = g_array_sized_new (FALSE, FALSE, sizeof (unsigned), len);
+	pids = g_array_sized_new (FALSE, FALSE, sizeof (pid_t), len);
 
 	for (i = 0; i < len; i++) {
-		unsigned pid;
+		pid_t pid;
 
-		pid = (unsigned) pinfo[i].ki_pid;
+		pid = (pid_t) pinfo[i].ki_pid;
 
 		switch (which & GLIBTOP_KERN_PROC_MASK) {
 			case GLIBTOP_KERN_PROC_ALL:
 				break;
 			case GLIBTOP_KERN_PROC_PID:
-				if ((unsigned) arg != pid)
+				if ((pid_t) arg != pid)
 					continue;
 				break;
 			case GLIBTOP_KERN_PROC_UID:
@@ -144,9 +144,9 @@ glibtop_get_proclist_p (glibtop *server,
 	g_free (pinfo);
 
 	buf->flags = _glibtop_sysdeps_proclist;
-	buf->size = sizeof (unsigned);
+	buf->size = sizeof (pid_t);
 	buf->number = pids->len;
 	buf->total = buf->number * buf->size;
 
-	return (unsigned *) g_array_free (pids, FALSE);
+	return (pid_t *) g_array_free (pids, FALSE);
 }
