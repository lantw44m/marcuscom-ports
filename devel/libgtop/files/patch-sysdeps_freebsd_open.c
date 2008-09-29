--- sysdeps/freebsd/open.c.orig	2008-05-23 18:13:23.000000000 -0400
+++ sysdeps/freebsd/open.c	2008-09-29 14:45:16.000000000 -0400
@@ -20,11 +20,14 @@
 */
 
 #include <config.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 #include <glibtop.h>
 #include <glibtop/error.h>
 #include <glibtop/open.h>
 #include <glibtop/init_hooks.h>
 
+
 /* !!! THIS FUNCTION RUNS SUID ROOT - CHANGE WITH CAUTION !!! */
 
 void
@@ -53,11 +56,17 @@ glibtop_open_p (glibtop *server, const c
 		const unsigned long features,
 		const unsigned flags)
 {
+	int ncpus;
+	size_t len;
 #ifdef DEBUG
 	fprintf (stderr, "DEBUG (%d): glibtop_open_p ()\n", getpid ());
 #endif
 
 	/* !!! WE ARE ROOT HERE - CHANGE WITH CAUTION !!! */
+	len = sizeof (ncpus);
+	sysctlbyname ("hw.ncpu", &ncpus, &len, NULL, 0);
+	server->real_ncpu = ncpus - 1;
+	server->ncpu = MIN(GLIBTOP_NCPU - 1, server->real_ncpu);
 
 	server->machine.uid = getuid ();
 	server->machine.euid = geteuid ();
