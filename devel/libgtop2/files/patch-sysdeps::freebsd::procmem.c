--- sysdeps/freebsd/procmem.c.orig	Fri Sep 24 18:49:06 2004
+++ sysdeps/freebsd/procmem.c	Sat Feb 26 03:53:09 2005
@@ -31,7 +31,7 @@
 #include <sys/param.h>
 #include <sys/proc.h>
 #include <sys/resource.h>
-#ifdef __NetBSD__ && (__NetBSD_Version__ >= 105020000)
+#if defined(__NetBSD__) && (__NetBSD_Version__ >= 105020000)
 #include <uvm/uvm_extern.h>
 #else
 #include <vm/vm_object.h>
@@ -47,7 +47,7 @@
 #include <sys/user.h>
 #endif
 #include <sys/sysctl.h>
-#ifdef __NetBSD__ && (__NetBSD_Version__ >= 105020000)
+#if defined(__NetBSD__) && (__NetBSD_Version__ >= 105020000)
 #include <uvm/uvm.h>
 #else
 #include <vm/vm.h>
@@ -125,7 +125,9 @@
 #else
 	struct vm_object object;
 #endif
+#if !defined(__FreeBSD__) || (__FreeBSD_version < 500013)
 	struct plimit plimit;
+#endif
 	int count;
 
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_PROC_MEM), 0);
