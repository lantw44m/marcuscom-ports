--- src/daemon.c.orig	2011-10-17 21:30:22.000000000 +0200
+++ src/daemon.c	2011-10-18 16:28:09.000000000 +0200
@@ -54,6 +54,9 @@
 #define PATH_LOGIN_DEFS "/etc/login.defs"
 #define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
 
+#ifdef __FreeBSD__
+#define FALLBACK_MINIMAL_UID 1000
+#endif
 #ifndef FALLBACK_MINIMAL_UID
 #define FALLBACK_MINIMAL_UID 500
 #endif
