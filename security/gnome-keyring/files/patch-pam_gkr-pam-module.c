--- pam/gkr-pam-module.c.orig	2007-08-10 15:46:32.000000000 -0400
+++ pam/gkr-pam-module.c	2007-08-14 01:19:49.000000000 -0400
@@ -41,6 +41,8 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 
+#include <security/pam_appl.h>
+
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
@@ -73,8 +75,10 @@ enum {
 #define  STDERR  2
 
 /* Linux/BSD compatibility */
-#ifndef PAM_AUTHTOK_RECOVERY_ERR
-#define PAM_AUTHTOK_RECOVERY_ERR PAM_AUTHTOK_RECOVER_ERR
+#ifndef PAM_AUTHTOK_RECOVER_ERR
+#ifdef PAM_AUTHTOK_RECOVERY_ERR
+#define PAM_AUTHTOK_RECOVER_ERR PAM_AUTHTOK_RECOVERY_ERR
+#endif
 #endif
 
 /* -----------------------------------------------------------------------------
