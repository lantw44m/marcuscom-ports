--- src/manager.c.orig	Tue May  2 22:50:07 2006
+++ src/manager.c	Tue May  2 22:51:16 2006
@@ -25,6 +25,8 @@
 #include <dirent.h>
 #include <signal.h>
 #include <unistd.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 
 #include <locale.h>
 
@@ -33,7 +35,6 @@
 #endif
 
 #ifdef ENABLE_NOTIFY
-#include <sys/vfs.h>
 #include <libnotify/notify.h>
 #endif
 
