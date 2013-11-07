--- daemon/gdm-session.orig.c	2013-08-28 16:29:01.973683917 +0000
+++ daemon/gdm-session.c	2013-08-28 16:29:10.164681622 +0000
@@ -980,7 +980,7 @@
         native_credentials = g_credentials_get_native (credentials, G_CREDENTIALS_TYPE_LINUX_UCRED);
         pid = (GPid) ((struct ucred *) native_credentials)->pid;
 #elif defined (__FreeBSD__)
-        native_credentials = g_credentials_get_native (credentials, G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED);
+        native_credentials = g_credentials_get_native (credentials, G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED);
         pid = (GPid) ((struct cmsgcred *) native_credentials)->cmcred_pid;
 #elif defined (__OpenBSD__)
         native_credentials = g_credentials_get_native (credentials, G_CREDENTIALS_TYPE_OPENBSD_SOCKPEERCRED);
