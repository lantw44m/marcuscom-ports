--- cd-recorder.c.orig	Wed Dec 10 14:36:05 2003
+++ cd-recorder.c	Wed Dec 10 14:36:38 2003
@@ -480,7 +480,7 @@
 
 	g_ptr_array_add (argv, "-Z");
 
-	dev_str = g_strdup_printf ("%s=%s", recorder->device, t->data.filename);
+	dev_str = g_strdup_printf ("%s=%s", recorder->device, t->contents.data.filename);
 	g_ptr_array_add (argv, dev_str);
 
 	g_ptr_array_add (argv, NULL);
@@ -634,12 +634,12 @@
 		case TRACK_TYPE_DATA:
 			g_ptr_array_add (argv, "-data");
 			g_ptr_array_add (argv, "-nopad"); /* TODO? */
-			g_ptr_array_add (argv, track->data.filename);
+			g_ptr_array_add (argv, track->contents.data.filename);
 			break;
 		case TRACK_TYPE_AUDIO:
 			g_ptr_array_add (argv, "-audio");
 			g_ptr_array_add (argv, "-pad");
-			g_ptr_array_add (argv, track->audio.filename);
+			g_ptr_array_add (argv, track->contents.audio.filename);
 			/* TODO: handle CD-TEXT somehow */
 			break;
 		default:
