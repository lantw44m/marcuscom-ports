--- tools/hal-storage-mount.c.orig	Sun May 14 16:52:00 2006
+++ tools/hal-storage-mount.c	Sun May 14 16:52:51 2006
@@ -441,6 +441,7 @@ handle_mount (LibHalContext *hal_ctx, Li
 	gboolean pol_change_uid;
 	char *privilege;
 	gboolean allowed_by_privilege;
+	gboolean is_temporary_privilege;
 	gboolean explicit_mount_point_given;
 	const char *end;
 
@@ -673,7 +674,8 @@ handle_mount (LibHalContext *hal_ctx, Li
 						    invoked_by_uid,
 						    privilege,
 						    udi,
-						    &allowed_by_privilege) != LIBPOLKIT_RESULT_OK) {
+						    &allowed_by_privilege,
+						    &is_temporary_privilege) != LIBPOLKIT_RESULT_OK) {
 		printf ("cannot lookup privilege\n");
 		unknown_error ();
 	}
