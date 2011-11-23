--- plparse/totem-pl-parser-videosite.c.orig	2011-11-23 17:32:50.000000000 +0100
+++ plparse/totem-pl-parser-videosite.c	2011-11-23 17:33:51.000000000 +0100
@@ -75,7 +75,7 @@ totem_pl_parser_add_videosite (TotemPlPa
 #ifdef HAVE_QUVI
 	QUVIcode rc;
 	quvi_t handle;
-	quvi_video_t v;
+	quvi_media_t v;
 	char *uri;
 	/* properties */
 	const char *video_uri;
@@ -104,8 +104,8 @@ totem_pl_parser_add_videosite (TotemPlPa
 		return TOTEM_PL_PARSER_RESULT_ERROR;
 	}
 
-	getprop (QUVIPROP_VIDEOURL, video_uri);
-	if (quvi_getprop (v, QUVIPROP_VIDEOFILELENGTH, &length) == QUVI_OK)
+	getprop (QUVIPROP_MEDIAURL, video_uri);
+	if (quvi_getprop (v, QUVIPROP_MEDIACONTENTLENGTH, &length) == QUVI_OK)
 		length_str = g_strdup_printf ("%f", length);
 	else
 		length_str = NULL;
