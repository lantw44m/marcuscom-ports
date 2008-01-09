--- gio/gunixmounts.c.orig	2008-01-07 09:15:54.000000000 -0500
+++ gio/gunixmounts.c	2008-01-07 18:39:57.000000000 -0500
@@ -215,20 +215,28 @@ g_unix_is_mount_path_system_internal (co
     "/",              /* we already have "Filesystem root" in Nautilus */ 
     "/bin",
     "/boot",
+    "/compat/linux/proc",
+    "/compat/linux/sys",
     "/dev",
     "/etc",
     "/home",
     "/lib",
     "/lib64",
+    "/libexec",
     "/media",
     "/mnt",
     "/opt",
+    "/rescue",
     "/root",
     "/sbin",
     "/srv",
     "/tmp",
     "/usr",
+    "/usr/X11R6",
     "/usr/local",
+    "/usr/obj",
+    "/usr/ports",
+    "/usr/src",
     "/var",
     "/var/log/audit", /* https://bugzilla.redhat.com/show_bug.cgi?id=333041 */
     "/var/tmp",       /* https://bugzilla.redhat.com/show_bug.cgi?id=335241 */
