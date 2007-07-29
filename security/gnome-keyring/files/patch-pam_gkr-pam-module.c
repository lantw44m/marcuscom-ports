--- pam/gkr-pam-module.c.orig	2007-07-29 17:48:01.000000000 -0400
+++ pam/gkr-pam-module.c	2007-07-29 17:50:09.000000000 -0400
@@ -40,6 +40,8 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 
+#include <security/pam_appl.h>
+
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
@@ -72,8 +74,8 @@ enum {
 #define  STDERR  2
 
 /* Linux/BSD compatibility */
-#ifndef PAM_AUTHTOK_RECOVERY_ERR
-#define PAM_AUTHTOK_RECOVERY_ERR PAM_AUTHTOK_RECOVER_ERR
+#ifndef PAM_AUTHTOK_RECOVER_ERR
+#define PAM_AUTHTOK_RECOVER_ERR PAM_AUTHTOK_RECOVERY_ERR
 #endif
 
 /* -----------------------------------------------------------------------------
