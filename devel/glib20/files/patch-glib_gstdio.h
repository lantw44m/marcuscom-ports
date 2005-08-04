--- glib/gstdio.h.orig	Thu Aug  4 13:44:25 2005
+++ glib/gstdio.h	Thu Aug  4 13:45:06 2005
@@ -25,10 +25,10 @@
 
 #include <sys/stat.h>
 
-#if defined(G_OS_UNIX) && !defined(G_STDIO_NO_WRAP_ON_UNIX)
-
 G_BEGIN_DECLS
 
+#if defined(G_OS_UNIX) && !defined(G_STDIO_NO_WRAP_ON_UNIX)
+
 /* Just pass on to the system functions, so there's no potential for data
  * format mismatches, especially with large file interfaces.
  */
@@ -100,8 +100,8 @@ FILE *g_freopen (const gchar *filename,
                  const gchar *mode,
                  FILE        *stream);
 
-G_END_DECLS
-
 #endif /* G_OS_UNIX */
+
+G_END_DECLS
 
 #endif /* __G_STDIO_H__ */
