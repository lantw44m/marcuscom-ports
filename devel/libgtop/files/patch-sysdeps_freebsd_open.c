--- sysdeps/freebsd/open.c.orig	2008-09-29 13:44:47.000000000 -0400
+++ sysdeps/freebsd/open.c	2008-09-29 13:49:37.000000000 -0400
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
@@ -53,11 +56,18 @@ glibtop_open_p (glibtop *server, const c
 		const unsigned long features,
 		const unsigned flags)
 {
+	guint64 ncpus;
+	size_t len;
 #ifdef DEBUG
 	fprintf (stderr, "DEBUG (%d): glibtop_open_p ()\n", getpid ());
 #endif
 
 	/* !!! WE ARE ROOT HERE - CHANGE WITH CAUTION !!! */
+	len = sizeof (ncpus);
+	sysctlbyname ("hw.ncpu", &ncpus, &len, NULL, 0);
+	server->ncpu = ncpus;
+	/* XXX We should detect HTT CPUs here. */
+	server->real_ncpu = ncpus;
 
 	server->machine.uid = getuid ();
 	server->machine.euid = geteuid ();
