--- libgnomevfs/gnome-vfs-volume-ops.c.orig	Wed Dec 24 13:53:43 2003
+++ libgnomevfs/gnome-vfs-volume-ops.c	Wed Dec 24 13:56:15 2003
@@ -224,12 +224,23 @@
 	}
 
 	if (info->should_eject) {
+#ifdef __FreeBSD__
+	    	char *argv[5] = {
+		    	"cdcontrol",
+			"-f",
+			NULL,
+			"eject",
+			NULL
+		};
+		argv[2] = info->device_path?info->device_path:info->mount_point;
+#else
 		char *argv[3] = {
 			"eject",
 			NULL,
 			NULL
 		};
 		argv[1] = info->device_path?info->device_path:info->mount_point;
+#endif
 
 		if (g_spawn_sync (NULL,
 				  argv,
