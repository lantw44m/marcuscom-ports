--- daemon/main.c.orig	2007-11-01 10:12:55.277503425 -0400
+++ daemon/main.c	2007-11-01 10:13:20.572202611 -0400
@@ -30,8 +30,9 @@
 #include <fcntl.h>
 #include <pwd.h>
 #include <grp.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <locale.h>
+#include <signal.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
