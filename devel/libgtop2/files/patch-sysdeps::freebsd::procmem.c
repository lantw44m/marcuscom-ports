--- sysdeps/freebsd/procmem.c.orig	Tue Oct 21 18:54:24 2003
+++ sysdeps/freebsd/procmem.c	Sun Feb 15 15:43:11 2004
@@ -117,7 +117,7 @@
 #else
 	struct vm_object object;
 #endif
-	struct plimit plimit;
+	struct rlimit rlimit;
 	int count;
 
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_PROC_MEM), 0);
@@ -136,16 +136,28 @@
 		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
 		return;
 	}
+#if __FreeBSD_version >= 500013
 
-	if (kvm_read (server->machine.kd,
-		      (unsigned long) pinfo [0].kp_proc.p_limit,
-		      (char *) &plimit, sizeof (plimit)) != sizeof (plimit)) {
-		glibtop_warn_io_r (server, "kvm_read (plimit)");
+#define		XXX_P_VMSPACE	ki_vmspace
+	buf->rss_rlim = pinfo [0].ki_rssize;
+
+	buf->vsize = (u_int64_t) pinfo [0].ki_size;
+	buf->size = (u_int64_t) pagetok
+	    	(pinfo [0].ki_tsize + pinfo [0].ki_dsize + pinfo[0].ki_ssize)
+			<< LOG1024;
+	buf->resident = buf->rss = (u_int64_t) pagetok
+	    	(pinfo [0].ki_rssize) << LOG1024;
+
+#else
+
+#define		XXX_P_VMSPACE	kp_proc.p_vmspace
+
+	if (getrlimit (RLIMIT_RSS, &rlimit) < 0) {
+	    	glibtop_warn_io_r (server, "getrlimit");
 		return;
 	}
 
-	buf->rss_rlim = (guint64) 
-		(plimit.pl_rlimit [RLIMIT_RSS].rlim_cur);
+	buf->rss_rlim = (u_int64_t) (rlimit.rlim_cur);
 	
 	vms = &pinfo [0].kp_eproc.e_vm;
 
@@ -154,11 +166,12 @@
 	
 	buf->resident = buf->rss = (guint64) pagetok
 		(vms->vm_rssize) << LOG1024;
+#endif
 
 	/* Now we get the shared memory. */
 
 	if (kvm_read (server->machine.kd,
-		      (unsigned long) pinfo [0].kp_proc.p_vmspace,
+		      (unsigned long) pinfo [0].XXX_P_VMSPACE,
 		      (char *) &vmspace, sizeof (vmspace)) != sizeof (vmspace)) {
 		glibtop_warn_io_r (server, "kvm_read (vmspace)");
 		return;
