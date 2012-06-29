--- src/fr-window.c.orig	2012-06-29 16:17:21.000000000 +0200
+++ src/fr-window.c	2012-06-29 16:18:38.000000000 +0200
@@ -6797,7 +6797,7 @@
 			g_object_unref (info);
 			g_object_unref (file);
 
-			return;
+			return FALSE;
 		}
 
 		g_object_unref (info);
@@ -6807,7 +6807,7 @@
 	if (do_not_extract) {
 		fr_window_stop_batch (odata->window);
 		g_free (odata);
-		return;
+		return FALSE;
 	}
 
 	odata->edata->overwrite = FR_OVERWRITE_YES;
