--- sysdeps/freebsd/procargs.c.orig	Fri Nov 14 14:39:42 2003
+++ sysdeps/freebsd/procargs.c	Fri Nov 14 14:43:40 2003
@@ -93,7 +93,7 @@
 		size += strlen (*ptr)+1;
 
 	size += 2;
-	retval = g_malloc (server, size);
+	retval = g_malloc (size);
 	memset (retval, 0, size);
 
 	for (ptr = args; *ptr; ptr++) {
