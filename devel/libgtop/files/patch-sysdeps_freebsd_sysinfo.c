--- sysdeps/freebsd/sysinfo.c.orig	2008-09-29 13:44:45.000000000 -0400
+++ sysdeps/freebsd/sysinfo.c	2008-09-29 13:50:06.000000000 -0400
@@ -45,8 +45,8 @@ init_sysinfo (glibtop *server)
 
 	glibtop_init_s (&server, GLIBTOP_SYSDEPS_CPU, 0);
 
-	len = sizeof (ncpus);
-	sysctlbyname ("hw.ncpu", &ncpus, &len, NULL, 0);
+	ncpus = server->ncpu;
+
 	len = 0;
 	sysctlbyname ("hw.model", NULL, &len, NULL, 0);
 	model = g_malloc (len);
