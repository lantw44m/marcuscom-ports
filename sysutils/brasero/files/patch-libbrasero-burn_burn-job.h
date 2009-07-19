--- libbrasero-burn/burn-job.h.orig	2009-07-19 00:56:11.000000000 -0400
+++ libbrasero-burn/burn-job.h	2009-07-19 00:56:41.000000000 -0400
@@ -155,6 +155,9 @@ BraseroBurnResult
 brasero_job_get_medium (BraseroJob *job, BraseroMedium **medium);
 
 BraseroBurnResult
+brasero_job_get_bus_target_lun (BraseroJob *job, gchar **BTL);
+
+BraseroBurnResult
 brasero_job_get_device (BraseroJob *job, gchar **device);
 
 BraseroBurnResult
