--- nautilus-cd-burner.c.orig	Wed Dec 10 14:36:52 2003
+++ nautilus-cd-burner.c	Wed Dec 10 14:37:13 2003
@@ -558,11 +558,11 @@
 {
 	switch (track->type) {
 	case TRACK_TYPE_DATA:
-		g_free (track->data.filename);
+		g_free (track->contents.data.filename);
 		break;
 	case TRACK_TYPE_AUDIO:
-		g_free (track->audio.filename);
-		g_free (track->audio.cdtext);
+		g_free (track->contents.audio.filename);
+		g_free (track->contents.audio.cdtext);
 		break;
 	default:
 		g_warning ("Invalid track type %d", track->type);
@@ -864,7 +864,7 @@
 			Track *track;
 			track = g_new0 (Track, 1);
 			track->type = TRACK_TYPE_DATA;
-			track->data.filename = g_strdup (filename);
+			track->contents.data.filename = g_strdup (filename);
 			tracks = g_list_prepend (tracks, track);
 		}
 		res = cd_recorder_write_tracks (cdrecorder, rec, tracks, speed, eject_cd, blank_cd, dummy);
