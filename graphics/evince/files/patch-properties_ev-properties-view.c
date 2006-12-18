--- properties/ev-properties-view.c.orig	Mon Dec 18 18:08:18 2006
+++ properties/ev-properties-view.c	Mon Dec 18 18:13:07 2006
@@ -245,10 +245,11 @@ ev_regular_paper_size (const EvDocumentI
 {
 	const struct regular_paper_size *size;   
 	char *exact_size = NULL;
-	char *imperial = NULL;
 	char *str = NULL;
 	int i;
 	
+#ifdef _NL_MEASUREMENT_MEASUREMENT
+	char *imperial = NULL;
         imperial = nl_langinfo(_NL_MEASUREMENT_MEASUREMENT);
         if ( imperial && imperial[0] == 2 )
 		/* Imperial measurement (inches) */
@@ -256,6 +257,7 @@ ev_regular_paper_size (const EvDocumentI
 					      info->paper_width  / 25.4f,
 					      info->paper_height / 25.4f );
 	else
+#endif
 		/* Metric measurement (millimeters) */
 		exact_size = g_strdup_printf( _("%.0f x %.0f mm"),
 					      info->paper_width,
