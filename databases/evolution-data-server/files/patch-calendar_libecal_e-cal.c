--- calendar/libecal/e-cal.c.orig	Mon Aug 30 13:26:41 2004
+++ calendar/libecal/e-cal.c	Mon Aug 30 13:26:58 2004
@@ -3131,7 +3131,7 @@
 {
 	ECalPrivate *priv;
 	GSList *alarms;
-	char *sexp, *iso_start, *iso_end;;
+	char *sexp, *iso_start, *iso_end;
 	GList *object_list = NULL;
 
 	g_return_val_if_fail (ecal != NULL, NULL);
