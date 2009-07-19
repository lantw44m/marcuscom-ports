--- libbrasero-burn/burn-job.c.orig	2009-07-19 00:53:38.000000000 -0400
+++ libbrasero-burn/burn-job.c	2009-07-19 00:55:41.000000000 -0400
@@ -1469,6 +1469,26 @@ brasero_job_get_action (BraseroJob *self
 }
 
 BraseroBurnResult
+brasero_job_get_bus_target_lun (BraseroJob *self, gchar **BTL)
+{
+	BraseroBurnSession *session;
+	BraseroJobPrivate *priv;
+	BraseroDrive *drive;
+
+	BRASERO_JOB_DEBUG (self);
+
+	g_return_val_if_fail (BTL != NULL, BRASERO_BURN_ERR);
+
+	priv = BRASERO_JOB_PRIVATE (self);
+	session = brasero_task_ctx_get_session (priv->ctx);
+
+	drive = brasero_burn_session_get_burner (session);
+	*BTL = brasero_drive_get_bus_target_lun_string (drive);
+
+	return BRASERO_BURN_OK;
+}
+
+BraseroBurnResult
 brasero_job_get_device (BraseroJob *self, gchar **device)
 {
 	BraseroBurnSession *session;
