--- libgswitchit/gswitchit_config.c.orig	Thu Oct 14 14:44:52 2004
+++ libgswitchit/gswitchit_config.c	Wed Nov 24 00:26:59 2004
@@ -380,44 +380,6 @@
 }
 
 static gboolean
-_GSwitchItXkbConfigDoWithSettings (GSwitchItXkbConfig *
-				   xkbConfig,
-				   gboolean activate,
-				   const char *psFileName)
-{
-	gboolean rv = FALSE;
-
-	XklConfigRec data;
-	XklConfigRecInit (&data);
-
-	_GSwitchItXkbConfigCopyToXklConfig (xkbConfig, &data);
-
-	if (activate) {
-		rv = XklConfigActivate (&data, NULL);
-	} else {
-		char *home = getenv ("HOME");
-		char xkmFileName[PATH_MAX];
-		char cmd[PATH_MAX * 2 + 20];
-		int status;
-		g_snprintf (xkmFileName, sizeof (xkmFileName),
-			    "%s/.gnome_private/xkbpreview.xkm", home);
-		rv = XklConfigWriteXKMFile (xkmFileName, &data, NULL);
-		if (rv) {
-			g_snprintf (cmd, sizeof (cmd),
-				    "xkbprint -full -color %s %s",
-				    xkmFileName, psFileName);
-			status = system (cmd);
-			XklDebug (100, "Res: [%d]\n", status);
-			//unlink( xkmFileName );
-		} else {
-			XklDebug (10, "Could not create XKM file!\n");
-		}
-	}
-	XklConfigRecDestroy (&data);
-	return rv;
-}
-
-static gboolean
 _GSListStrEqual (GSList * l1, GSList * l2)
 {
 	if (l1 == l2)
@@ -752,15 +714,16 @@
 gboolean
 GSwitchItXkbConfigActivate (GSwitchItXkbConfig * xkbConfig)
 {
-	return _GSwitchItXkbConfigDoWithSettings (xkbConfig, TRUE, NULL);
-}
+	gboolean rv = FALSE;
 
-gboolean
-GSwitchItXkbConfigDumpSettings (GSwitchItXkbConfig * xkbConfig,
-				const char *fileName)
-{
-	return _GSwitchItXkbConfigDoWithSettings (xkbConfig, FALSE,
-						  fileName);
+	XklConfigRec data;
+	XklConfigRecInit (&data);
+
+	_GSwitchItXkbConfigCopyToXklConfig (xkbConfig, &data);
+
+	rv = XklConfigActivate (&data);
+	XklConfigRecDestroy (&data);
+	return rv;
 }
 
 void
