--- panels/user-accounts/um-utils.orig.c	2013-02-28 12:30:49.816494890 +0100
+++ panels/user-accounts/um-utils.c	2013-02-28 12:32:17.656493654 +0100
@@ -23,9 +23,10 @@
 
 #include <math.h>
 #include <stdlib.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <pwd.h>
-#include <utmp.h>
+#include <utmpx.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -445,7 +446,7 @@
 }
 
 
-#define MAXNAMELEN  (UT_NAMESIZE - 1)
+#define MAXNAMELEN  (MAXLOGNAME - 1)
 
 static gboolean
 is_username_used (const gchar *username)
