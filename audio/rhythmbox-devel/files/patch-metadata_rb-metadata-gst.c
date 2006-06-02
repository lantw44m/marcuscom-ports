--- metadata/rb-metadata-gst.c.orig	Fri Jun  2 15:42:35 2006
+++ metadata/rb-metadata-gst.c	Fri Jun  2 16:15:13 2006
@@ -1065,10 +1065,8 @@ rb_metadata_load (RBMetaData *md,
 				     "%s", msg);
 			g_free (msg);
 		} else {
-			g_set_error (error,
-				     RB_METADATA_ERROR,
-				     RB_METADATA_ERROR_NOT_AUDIO_IGNORE,
-				     NULL);
+			if (error != NULL)
+				*error = NULL;
 		}
 	} else {
 		/* yay, it worked */
