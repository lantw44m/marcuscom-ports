===================================================================
RCS file: /space/cvs/marcuscom-cvs/libgtop/sysdeps/freebsd/procmap.c,v
retrieving revision 1.7
retrieving revision 1.8
diff -u -p -r1.7 -r1.8
--- sysdeps/freebsd/procmap.c	2007/01/02 05:35:35	1.7
+++ sysdeps/freebsd/procmap.c	2007/01/14 19:33:17	1.8
@@ -1,4 +1,4 @@
-/* $Id: patch-sysdeps_freebsd_procmap.c,v 1.1 2007-01-14 19:42:18 marcus Exp $ */
+/* $Id: patch-sysdeps_freebsd_procmap.c,v 1.1 2007-01-14 19:42:18 marcus Exp $ */
 
 /* Copyright (C) 1998 Joshua Sled
    This file is part of LibGTop 1.0.
@@ -48,7 +48,9 @@
 #include <ufs/ufs/quota.h>
 #include <ufs/ufs/inode.h>
 #include <fs/devfs/devfs.h>
+#if (__FreeBSD_version >= 600006) || defined(__FreeBSD_kernel__)
 #include <fs/devfs/devfs_int.h>
+#endif
 #undef _KERNEL
 
 #include <sys/ucred.h>
