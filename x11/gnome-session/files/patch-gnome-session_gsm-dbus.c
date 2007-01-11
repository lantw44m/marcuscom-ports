--- gnome-session/gsm-dbus.c.orig	Thu Jan 11 12:59:48 2007
+++ gnome-session/gsm-dbus.c	Thu Jan 11 13:00:47 2007
@@ -281,6 +281,7 @@ start_parent (int address_fd, int pid_fd
   int exitstat;
   unsigned long tmp_num;
   ssize_t bytes;
+  int i;
 
   g_assert (child > 0);
 
@@ -326,17 +327,18 @@ start_parent (int address_fd, int pid_fd
   /*
    * Fetch dbus-daemon pid.
    */
-  bytes = read_line (pid_fd, pid_str, sizeof (pid_str));
-  if (bytes == -1 || bytes == 0)
+  for (i = 0; i < 2; i++)
     {
-      close (address_fd);
-      close (pid_fd);
-
-      g_printerr ("Failed to get dbus-daemon's pid\n");
-      return;
+      bytes = read_line (pid_fd, pid_str, sizeof (pid_str));
+      if (bytes == -1 || bytes == 0)
+        {
+          close (address_fd);
+          close (pid_fd);
+
+          g_printerr ("Failed to get dbus-daemon's pid\n");
+          return;
+        }
     }
-
-  bytes = read_line (pid_fd, pid_str, sizeof (pid_str));
 
   close (address_fd);
   close (pid_fd);
