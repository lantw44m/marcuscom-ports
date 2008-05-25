--- sysdeps/freebsd/glibtop_server.h.orig	2008-05-25 14:26:13.000000000 -0400
+++ sysdeps/freebsd/glibtop_server.h	2008-05-25 14:26:30.000000000 -0400
@@ -46,6 +46,7 @@ G_BEGIN_DECLS
 #define GLIBTOP_SUID_SEM_LIMITS		0
 #define GLIBTOP_SUID_NETLIST		0
 #define GLIBTOP_SUID_PROC_WD		0
+#define GLIBTOP_SUID_PROC_AFFINITY	0
 
 G_END_DECLS
 
