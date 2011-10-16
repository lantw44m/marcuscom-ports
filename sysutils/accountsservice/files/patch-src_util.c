--- src/util.c.orig	2011-10-16 20:25:37.000000000 +0200
+++ src/util.c	2011-10-16 20:24:33.000000000 +0200
@@ -24,8 +24,8 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include <fcntl.h>
-#include <wait.h>
 #include <grp.h>
 
 #include <syslog.h>
