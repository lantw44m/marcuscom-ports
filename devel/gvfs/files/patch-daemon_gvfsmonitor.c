--- daemon/gvfsmonitor.c.orig	2008-01-09 03:13:27.000000000 -0500
+++ daemon/gvfsmonitor.c	2008-01-09 03:13:35.000000000 -0500
@@ -223,9 +223,9 @@ g_vfs_monitor_new (GVfsDaemon *daemon)
 			      vfs_monitor_message_callback,
 			      monitor);
 
-  g_timeout_add (5000,
+/*  g_timeout_add (5000,
 		 vfs_monitor_initial_unref,
-		 monitor);
+		 monitor);*/
 
   return monitor;  
 }
