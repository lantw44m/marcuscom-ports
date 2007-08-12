--- pam/gkr-pam-client.c.orig	2007-08-12 16:42:30.000000000 -0400
+++ pam/gkr-pam-client.c	2007-08-12 16:43:46.000000000 -0400
@@ -29,6 +29,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/ucred.h>
 #include <sys/un.h>
 #include <sys/uio.h>
 #include <sys/wait.h>
@@ -90,7 +91,7 @@ check_peer_same_uid (int sock)
         socklen_t xuc_len = sizeof (xuc);
 
 	if (getsockopt (sock, SOL_SOCKET, LOCAL_PEERCRED, &xuc, &xuc_len) == 0 && 
-	    xuc_len == sizeof (xuc) {
+	    xuc_len == sizeof (xuc)) {
 	    	uid = xuc.cr_uid;
 	} else {
 		syslog (GKR_LOG_ERR, "could not get gnome-keyring-daemon socket credentials, "
