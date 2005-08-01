--- sysdeps/freebsd/proctime.c.orig	Wed Feb 23 00:20:45 2005
+++ sysdeps/freebsd/proctime.c	Mon Aug  1 12:02:29 2005
@@ -146,8 +146,10 @@
 
 	/* Get the process information */
 	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
-	if ((pinfo == NULL) || (count != 1))
-		glibtop_error_io_r (server, "kvm_getprocs (%d)", pid);
+	if ((pinfo == NULL) || (count != 1)) {
+		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
+		return;
+	}
 
 #if defined(__FreeBSD__) && (__FreeBSD_version >= 500013)
 	buf->rtime = pinfo [0].ki_runtime;
@@ -193,9 +195,9 @@
        if ((pinfo [0].ki_flag & P_INMEM)) {
 #endif
            buf->utime = pinfo [0].ki_runtime;
-           buf->stime = 0; /* XXX */
+		   buf->stime = tv2sec (pinfo [0].ki_rusage.ru_stime);
            buf->cutime = tv2sec (pinfo [0].ki_childtime);
-           buf->cstime = 0; /* XXX */
+		   buf->cstime = tv2sec (pinfo [0].ki_rusage_ch.ru_stime);
            buf->start_time = tv2sec (pinfo [0].ki_start);
            buf->flags = _glibtop_sysdeps_proc_time_user;
        }
