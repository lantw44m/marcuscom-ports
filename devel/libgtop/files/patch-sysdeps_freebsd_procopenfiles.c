--- sysdeps/freebsd/procopenfiles.c.orig	Fri Jun  8 19:58:17 2007
+++ sysdeps/freebsd/procopenfiles.c	Fri Jun  8 19:59:15 2007
@@ -27,12 +27,7 @@
 #include <glibtop/error.h>
 #include <glibtop/procopenfiles.h>
 
-#include <glibtop_suid.h>
-
-static const unsigned long _glibtop_sysdeps_proc_open_files =
-(1L << GLIBTOP_PROC_OPEN_FILES_NUMBER)|
-(1L << GLIBTOP_PROC_OPEN_FILES_TOTAL)|
-(1L << GLIBTOP_PROC_OPEN_FILES_SIZE);
+static const unsigned long _glibtop_sysdeps_proc_open_files = 0;
 
 /* Init function. */
 
@@ -47,5 +42,6 @@ _glibtop_init_proc_open_files_s (glibtop
 glibtop_open_files_entry *
 glibtop_get_proc_open_files_s (glibtop *server, glibtop_proc_open_files *buf,	pid_t pid)
 {
+	memset(buf, 0, sizeof(glibtop_proc_open_files));
 	return NULL;
 }
