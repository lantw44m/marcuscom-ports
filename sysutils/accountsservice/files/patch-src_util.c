--- src/util.c.orig	2011-03-27 20:32:32.000000000 +0200
+++ src/util.c	2011-03-27 20:32:54.000000000 +0200
@@ -25,7 +25,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <grp.h>
 
 #include <syslog.h>
