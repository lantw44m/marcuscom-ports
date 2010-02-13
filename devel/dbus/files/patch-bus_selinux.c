--- bus/selinux.c.orig	2010-02-13 13:50:50.000000000 -0500
+++ bus/selinux.c	2010-02-13 13:56:22.000000000 -0500
@@ -29,7 +29,6 @@
 #include "utils.h"
 #include "config-parser.h"
 
-#ifdef HAVE_SELINUX
 #include <sys/types.h>
 #include <unistd.h>
 #ifdef HAVE_ERRNO_H
@@ -38,10 +37,12 @@
 #include <limits.h>
 #include <pthread.h>
 #include <syslog.h>
+#ifdef HAVE_SELINUX
 #include <selinux/selinux.h>
 #include <selinux/avc.h>
 #include <selinux/av_permissions.h>
 #include <selinux/flask.h>
+#endif /* HAVE_LIBAUDIT */
 #include <signal.h>
 #include <stdarg.h>
 #include <stdio.h>
@@ -49,7 +50,6 @@
 #ifdef HAVE_LIBAUDIT
 #include <cap-ng.h>
 #include <libaudit.h>
-#endif /* HAVE_LIBAUDIT */
 #endif /* HAVE_SELINUX */
 
 #define BUS_SID_FROM_SELINUX(sid)  ((BusSELinuxID*) (sid))
