--- libgnomevfs/gnome-vfs-resolve.c.orig	Tue Jul 20 14:39:26 2004
+++ libgnomevfs/gnome-vfs-resolve.c	Thu Jul 22 16:38:35 2004
@@ -133,8 +133,10 @@
 	switch (error) {
 
 	case EAI_NONAME: return GNOME_VFS_ERROR_HOST_NOT_FOUND;
+#if defined(EAI_ADDRFAMILY) && defined(EAI_NODATA)
 	case EAI_ADDRFAMILY:		
 	case EAI_NODATA: return GNOME_VFS_ERROR_HOST_HAS_NO_ADDRESS;
+#endif
 	case EAI_SYSTEM: return gnome_vfs_result_from_errno ();
 	case EAI_FAIL:
 	case EAI_AGAIN: return GNOME_VFS_ERROR_NAMESERVER;
