--- modules/sftp-method.c.orig	Sat Apr  3 23:58:06 2004
+++ modules/sftp-method.c	Sun Apr  4 00:00:38 2004
@@ -174,6 +174,15 @@
 /* Inspired by atomicio() from OpenSSH */
 
 typedef ssize_t (*read_write_fn) (int, void *, size_t);
+
+#ifndef TEMP_FAILURE_RETRY
+#define TEMP_FAILURE_RETRY(expression)				\
+	(__extension__						\
+	 ({ long int __result;					\
+	  	do __result = (long int) (expression);		\
+		while (__result == -1L && errno == EINTR);	\
+		__result; }))
+#endif
 
 static gsize
 atomic_io (read_write_fn f, gint fd, gpointer buffer_in, gsize size) 
