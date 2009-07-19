--- plugins/cdrdao/burn-cdrdao.c.orig	2009-07-19 00:48:09.000000000 -0400
+++ plugins/cdrdao/burn-cdrdao.c	2009-07-19 00:49:59.000000000 -0400
@@ -346,7 +346,11 @@ brasero_cdrdao_set_argv_record (BraseroC
 		brasero_job_get_current_track (BRASERO_JOB (cdrdao), &track);
 		drive = brasero_track_disc_get_drive (BRASERO_TRACK_DISC (track));
 
+#ifdef HAVE_CAM_LIB_H
+		g_ptr_array_add (argv, brasero_drive_get_bus_target_lun_string (drive));
+#else
 		g_ptr_array_add (argv, g_strdup (brasero_drive_get_device (drive)));
+#endif
 	}
 	else if (brasero_track_type_get_has_image (type)) {
 		gchar *cuepath;
@@ -442,7 +446,11 @@ brasero_cdrdao_set_argv_image (BraseroCd
 	brasero_job_get_current_track (BRASERO_JOB (cdrdao), &track);
 	drive = brasero_track_disc_get_drive (BRASERO_TRACK_DISC (track));
 
+#ifdef HAVE_CAM_LIB_H
+	g_ptr_array_add (argv, brasero_drive_get_bus_target_lun_string (drive));
+#else
 	g_ptr_array_add (argv, g_strdup (brasero_drive_get_device (drive)));
+#endif
 	g_ptr_array_add (argv, g_strdup ("--read-raw"));
 
 	/* This is done so that if a cue file is required we first generate
