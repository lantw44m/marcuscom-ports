--- modules/smb-method.c.orig	Mon Sep 12 02:29:46 2005
+++ modules/smb-method.c	Mon Sep 12 02:30:57 2005
@@ -1486,7 +1486,7 @@ do_close (GnomeVFSMethod *method,
 
 		/* Important: perform_authentication leaves and re-enters the lock! */
 		while (perform_authentication (&actx) > 0) {
-			r = smb_context->close (smb_context, handle->file);
+			r = smb_context->close_fn (smb_context, handle->file);
 			actx.res = (r >= 0) ? GNOME_VFS_OK : gnome_vfs_result_from_errno ();
 		}
 
