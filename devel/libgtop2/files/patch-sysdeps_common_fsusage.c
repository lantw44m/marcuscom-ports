--- sysdeps/common/fsusage.c.orig	Tue Jul 20 22:05:56 2004
+++ sysdeps/common/fsusage.c	Tue Jul 20 22:10:04 2004
@@ -147,6 +147,24 @@
 glibtop_get_fsusage_s (glibtop *server, glibtop_fsusage *buf,
 		       const char *path)
 {
+#ifdef STAT_STATFS3_OSF1
+  struct statfs fsd;
+#endif
+#ifdef STAT_STATFS2_FS_DATA
+  struct fs_data fsd;
+#endif
+#ifdef STAT_STATFS2_BSIZE
+  struct statfs fsd;
+#endif
+#ifdef STAT_STATFS2_FSIZE
+  struct statfs fsd;
+#endif
+#ifdef STAT_STATFS4
+  struct statvfs fsd;
+#endif
+#ifdef STAT_STATVFS
+  struct statvfs fsd;
+#endif
   glibtop_init_r (&server, 0, 0);
 
   memset (buf, 0, sizeof (glibtop_fsusage));
@@ -155,8 +173,6 @@
 
 #ifdef STAT_STATFS3_OSF1
 
-  struct statfs fsd;
-
   if (statfs (path, &fsd, sizeof (struct statfs)) != 0)
     return;
 
@@ -166,8 +182,6 @@
 
 #ifdef STAT_STATFS2_FS_DATA	/* Ultrix */
 
-  struct fs_data fsd;
-
   if (statfs (path, &fsd) != 1)
     return;
 
@@ -183,8 +197,6 @@
 
 #ifdef STAT_STATFS2_BSIZE	/* 4.3BSD, SunOS 4, HP-UX, AIX */
 
-  struct statfs fsd;
-
   if (statfs (path, &fsd) < 0)
     return;
 
@@ -209,8 +221,6 @@
 
 #ifdef STAT_STATFS2_FSIZE	/* 4.4BSD */
 
-  struct statfs fsd;
-
   if (statfs (path, &fsd) < 0)
     return;
 
@@ -224,8 +234,6 @@
 #  define f_bavail f_bfree
 # endif
 
-  struct statfs fsd;
-
   if (statfs (path, &fsd, sizeof fsd, 0) < 0)
     return;
 
@@ -241,8 +249,6 @@
 #endif /* STAT_STATFS4 */
 
 #ifdef STAT_STATVFS		/* SVR4 */
-
-  struct statvfs fsd;
 
   if (statvfs (path, &fsd) < 0)
     return;
