--- sysdeps/freebsd/procmem.c.orig	Fri Sep 24 18:49:06 2004
+++ sysdeps/freebsd/procmem.c	Sat Feb 26 02:24:39 2005
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
