--- gconf/gconf-internals.c.orig	Wed Mar 26 13:52:31 2003
+++ gconf/gconf-internals.c	Sat Apr 12 02:02:23 2003
@@ -26,6 +26,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
@@ -2781,7 +2784,7 @@
 char*
 gconf_get_daemon_dir (void)
 {
-  if (gconf_use_local_locks ())
+  if (!gconf_use_local_locks ())
     return linc_get_tmpdir ();
   else
     return g_strconcat (g_get_home_dir (), "/.gconfd", NULL);
