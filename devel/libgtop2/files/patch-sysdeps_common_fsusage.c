--- sysdeps/common/fsusage.c.orig	Thu Dec 23 16:56:10 2004
+++ sysdeps/common/fsusage.c	Fri Feb 25 21:55:06 2005
@@ -134,6 +134,15 @@
 #define _glibtop_get_fsusage_read_write(S, B, P) \
         _glibtop_linux_get_fsusage_read_write(S, B, P)
 
+#elif defined(__FreeBSD__)
+void G_GNUC_INTERNAL
+_glibtop_freebsd_get_fsusage_read_write(glibtop *server,
+					glibtop_fsusage *buf,
+					const char *path);
+
+#define _glibtop_get_fsusage_read_write(S, B, P) \
+	_glibtop_freebsd_get_fsusage_read_write(S, B, P)
+
 #else /* default fallback */
 #warning glibtop_get_fsusage .read .write are not implemented.
 static inline void
@@ -254,8 +263,9 @@
   if (statvfs (path, &fsd) < 0)
     return;
 
-#if (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
-  /* Solaris but not SunOS */
+#if (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__)) \
+	|| defined(__FreeBSD__)
+  /* Solaris but not SunOS and FreeBSD */
   buf->block_size = fsd.f_frsize;
 #else
   /* else, including Linux */
