--- plugins/cdrtools/burn-readcd.c.orig	2009-07-19 00:50:30.000000000 -0400
+++ plugins/cdrtools/burn-readcd.c	2009-07-19 00:51:10.000000000 -0400
@@ -344,7 +344,11 @@ brasero_readcd_set_argv (BraseroProcess 
 	brasero_job_get_current_track (BRASERO_JOB (readcd), &track);
 	drive = brasero_track_disc_get_drive (BRASERO_TRACK_DISC (track));
 
+#ifdef HAVE_CAM_LIB_H
+	device = brasero_drive_get_bus_target_lun_string (drive);
+#else
 	device = g_strdup (brasero_drive_get_device (drive));
+#endif
 
 	if (!device)
 		return BRASERO_BURN_ERR;
