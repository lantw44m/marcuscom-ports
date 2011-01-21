--- panels/user-accounts/um-account-dialog.c.orig	2011-01-21 09:07:21.000000000 +0100
+++ panels/user-accounts/um-account-dialog.c	2011-01-21 09:16:37.000000000 +0100
@@ -24,7 +24,16 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <pwd.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 900000
 #include <utmp.h>
+#else
+#include <utmpx.h>
+/* from the old utmp.h */
+#define UT_NAMESIZE 16
+#endif
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
