--- make-iso.c.orig	Fri Dec 19 13:06:34 2003
+++ make-iso.c	Mon Dec 29 16:18:15 2003
@@ -571,6 +571,7 @@
 	argv[i++] = "-r";
 	if (use_joliet) {
 		argv[i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	argv[i++] = "-q";
 	argv[i++] = "-graft-points";
@@ -650,6 +651,7 @@
 	argv[i++] = "-r";
 	if (use_joliet) {
 		argv[i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	argv[i++] = "-graft-points";
 	argv[i++] = "-path-list";
@@ -755,8 +757,8 @@
 			backing = get_backing_file (info->name);
 			track = g_new0 (Track, 1);
 			track->type = TRACK_TYPE_AUDIO;
-			track->audio.filename = backing;
-			track->audio.cdtext = NULL;
+			track->contents.audio.filename = backing;
+			track->contents.audio.cdtext = NULL;
 			list = g_list_prepend (list, track);
 		}
 	}
