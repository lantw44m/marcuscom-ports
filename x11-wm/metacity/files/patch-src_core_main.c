--- src/core/main.c.orig	2009-05-03 11:54:25.000000000 +0200
+++ src/core/main.c	2009-05-03 11:55:24.000000000 +0200
@@ -58,7 +58,11 @@
 
 #include <stdlib.h>
 #include <sys/types.h>
+#ifdef __linux__
 #include <wait.h>
+#else
+#include <sys/wait.h>
+#endif
 #include <stdio.h>
 #include <string.h>
 #include <signal.h>
