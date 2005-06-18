--- plugins/terminal/terminal.c.orig	Sun May 22 21:38:41 2005
+++ plugins/terminal/terminal.c	Sun May 22 21:39:12 2005
@@ -19,6 +19,9 @@
 */
 
 #include <config.h>
+
+#include <sys/signal.h>
+
 #include <libanjuta/anjuta-shell.h>
 #include <libanjuta/anjuta-children.h>
 #include <libanjuta/anjuta-debug.h>
