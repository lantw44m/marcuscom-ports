--- pam/gkr-pam-client.c.orig	2007-08-10 15:28:07.000000000 -0400
+++ pam/gkr-pam-client.c	2007-08-15 19:37:52.000000000 -0400
@@ -47,6 +47,11 @@
 #include <ucred.h>
 #endif
 
+#if defined(LOCAL_PEERCRED)
+#include <sys/param.h>
+#include <sys/ucred.h>
+#endif
+
 #define PAM_APP_NAME      "Auto Login (PAM)"
 #define PAM_APP_NAME_LEN  (sizeof (PAM_APP_NAME) - 1)
 
@@ -90,7 +95,7 @@ check_peer_same_uid (int sock)
         socklen_t xuc_len = sizeof (xuc);
 
 	if (getsockopt (sock, SOL_SOCKET, LOCAL_PEERCRED, &xuc, &xuc_len) == 0 && 
-	    xuc_len == sizeof (xuc) {
+	    xuc_len == sizeof (xuc)) {
 	    	uid = xuc.cr_uid;
 	} else {
 		syslog (GKR_LOG_ERR, "could not get gnome-keyring-daemon socket credentials, "
