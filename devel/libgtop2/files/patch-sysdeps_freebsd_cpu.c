--- sysdeps/freebsd/cpu.c.orig	Sat Feb 26 00:43:48 2005
+++ sysdeps/freebsd/cpu.c	Fri Feb 25 21:44:42 2005
@@ -34,7 +34,8 @@
 static const unsigned long _glibtop_sysdeps_cpu =
 (1L << GLIBTOP_CPU_TOTAL) + (1L << GLIBTOP_CPU_USER) +
 (1L << GLIBTOP_CPU_NICE) + (1L << GLIBTOP_CPU_SYS) +
-(1L << GLIBTOP_CPU_IDLE) + (1L << GLIBTOP_CPU_FREQUENCY);
+(1L << GLIBTOP_CPU_IDLE) + (1L << GLIBTOP_CPU_FREQUENCY) +
+(1L << GLIBTOP_CPU_IOWAIT);
 
 #ifndef KERN_CP_TIME
 /* nlist structure for kernel access */
@@ -122,6 +123,8 @@
 	buf->sys = cpts [CP_SYS];
 	/* set idle time */
 	buf->idle = cpts [CP_IDLE];
+	/* set iowait (really just interrupt) time */
+	buf->iowait = cpts [CP_INTR];
 
 	/* set frequency */
 	/*
