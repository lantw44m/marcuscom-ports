--- calendar/gui/e-tasks.c.orig	Wed May 19 11:07:08 2004
+++ calendar/gui/e-tasks.c	Wed Jun  2 14:45:05 2004
@@ -558,6 +558,8 @@
 	ETasksPrivate *priv;
 	va_list args;
 	char sz[2048];
+
+	g_return_if_fail (message != NULL);
 	
 	va_start (args, message);
 	vsnprintf (sz, sizeof sz, message, args);
