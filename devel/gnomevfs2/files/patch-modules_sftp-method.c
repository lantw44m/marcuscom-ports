--- modules/sftp-method.c.orig	Sat Apr  3 23:58:06 2004
+++ modules/sftp-method.c	Sun Apr  4 00:00:38 2004
@@ -72,7 +72,7 @@
 size_t default_req_len = 32768;
 guint max_req = 16;
 
-#ifdef HAVE_GRANTPT
+#if defined(HAVE_GRANTPT) && !defined(__FreeBSD__)
 /* We only use this on systems with unix98 ptys */
 #define USE_PTY 1
 #endif
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
