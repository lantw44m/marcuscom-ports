--- sysdeps/common/mountlist.c.orig	Thu Jul  8 09:48:08 2004
+++ sysdeps/common/mountlist.c	Tue Jul 20 22:05:02 2004
@@ -95,7 +95,7 @@
 #endif
 
 
-#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__)
+#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
 static const char *
 fstype_to_string (short t)
 {
@@ -300,7 +300,7 @@
 	me = (struct mount_entry *) g_malloc (sizeof (struct mount_entry));
 	me->me_devname = g_strdup (fsp->f_mntfromname);
 	me->me_mountdir = g_strdup (fsp->f_mntonname);
-#if defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 	me->me_type = g_strdup (fsp->f_fstypename);
 #else
 	me->me_type = g_strdup (fstype_to_string (fsp->f_type));
