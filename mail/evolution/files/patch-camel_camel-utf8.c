--- camel/camel-utf8.c.orig	Tue Dec  9 15:21:35 2003
+++ camel/camel-utf8.c	Tue Dec  9 15:21:43 2003
@@ -25,6 +25,7 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <string.h>
 
 #include <glib.h>
