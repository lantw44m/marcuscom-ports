--- make-iso.c.orig	Fri Dec  5 15:16:04 2003
+++ make-iso.c	Wed Dec 10 14:30:52 2003
@@ -551,6 +551,7 @@
 	argv[i++] = "mkisofs";
 	argv[i++] = "-r";
 	argv[i++] = "-J";
+	argv[i++] = "-joliet-long";
 	argv[i++] = "-graft-points";
 	argv[i++] = "-path-list";
 	argv[i++] = filelist;
@@ -611,6 +612,7 @@
 	argv[i++] = "mkisofs";
 	argv[i++] = "-r";
 	argv[i++] = "-J";
+	argv[i++] = "-joliet-long";
 	argv[i++] = "-graft-points";
 	argv[i++] = "-path-list";
 	argv[i++] = filelist;
@@ -715,8 +717,8 @@
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
