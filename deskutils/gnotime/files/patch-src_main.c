--- src/main.c.orig	Sat Apr  3 20:46:44 2004
+++ src/main.c	Sun Apr 25 15:35:31 2004
@@ -32,7 +32,7 @@
 #include <unistd.h>
 #include <utime.h>
 #if defined(HAVE_DECL_WNOHANG) && defined(HAVE_WAITPID)
-#include <wait.h>
+#include <sys/wait.h>
 #endif
 
 #include <qof.h>
