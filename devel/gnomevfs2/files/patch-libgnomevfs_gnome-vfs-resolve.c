--- libgnomevfs/gnome-vfs-resolve.c.orig	Thu Jul 22 11:23:42 2004
+++ libgnomevfs/gnome-vfs-resolve.c	Thu Jul 22 11:25:46 2004
@@ -133,8 +133,10 @@
 	switch (error) {
 
 	case EAI_NONAME: return GNOME_VFS_ERROR_HOST_NOT_FOUND;
+#ifndef __FreeBSD__
 	case EAI_ADDRFAMILY:		
 	case EAI_NODATA: return GNOME_VFS_ERROR_HOST_HAS_NO_ADDRESS;
+#endif
 	case EAI_SYSTEM: return gnome_vfs_result_from_errno ();
 	case EAI_FAIL:
 	case EAI_AGAIN: return GNOME_VFS_ERROR_NAMESERVER;
