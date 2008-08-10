--- dbus/dbus-sysdeps-util-unix.c.orig	2008-08-10 15:04:41.000000000 -0400
+++ dbus/dbus-sysdeps-util-unix.c	2008-08-10 15:05:16.000000000 -0400
@@ -836,7 +836,7 @@ fill_group_info (DBusGroupInfo    *info,
     /* retrieve maximum needed size for buf */
     buflen = sysconf (_SC_GETGR_R_SIZE_MAX);
 
-    if (buflen <= 0)
+    if ((long) buflen <= 0)
       buflen = 1024;
 
     result = -1;
