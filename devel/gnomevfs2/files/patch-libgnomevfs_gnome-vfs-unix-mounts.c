--- libgnomevfs/gnome-vfs-unix-mounts.c.orig	Mon Nov 10 18:09:17 2003
+++ libgnomevfs/gnome-vfs-unix-mounts.c	Mon Nov 10 18:13:26 2003
@@ -398,16 +398,6 @@
 		    	mount_entry->is_read_only = TRUE;
 		}
 
-#ifdef HAVE_SYS_SYSCTL_H
-		if (usermnt != 0) {
-			if (stat (fstab->fs_file, &sb) == 0) {
-				if (sb.st_uid != 0) {
-					mount_entry->is_user_mountable = TRUE;
-				}
-			}
-		}
-#endif
-
 		*return_list = g_list_prepend (*return_list, mount_entry);
 	}
 
