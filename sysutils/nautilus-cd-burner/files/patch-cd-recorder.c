--- cd-recorder.c.orig	Fri Dec 19 13:06:34 2003
+++ cd-recorder.c	Mon Dec 29 16:16:41 2003
@@ -482,7 +482,7 @@
 
 	g_ptr_array_add (argv, "-Z");
 
-	dev_str = g_strdup_printf ("%s=%s", recorder->device, t->data.filename);
+	dev_str = g_strdup_printf ("%s=%s", recorder->device, t->contents.data.filename);
 	g_ptr_array_add (argv, dev_str);
 
 	g_ptr_array_add (argv, NULL);
@@ -640,13 +640,13 @@
 		case TRACK_TYPE_DATA:
 			g_ptr_array_add (argv, "-data");
 			g_ptr_array_add (argv, "-nopad"); /* TODO? */
-			g_ptr_array_add (argv, track->data.filename);
+			g_ptr_array_add (argv, track->contents.data.filename);
 			break;
 		case TRACK_TYPE_AUDIO:
 			g_ptr_array_add (argv, "-copy");
 			g_ptr_array_add (argv, "-audio");
 			g_ptr_array_add (argv, "-pad");
-			g_ptr_array_add (argv, track->audio.filename);
+			g_ptr_array_add (argv, track->contents.audio.filename);
 			/* TODO: handle CD-TEXT somehow */
 			break;
 		default:
