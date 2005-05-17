--- make-iso.c.orig	Tue May 17 17:16:17 2005
+++ make-iso.c	Tue May 17 17:16:31 2005
@@ -740,7 +740,7 @@ get_average_rate (GList  **rates,
 	if (g_list_length (*rates) > max_num) {
 		*rates = g_list_delete_link (*rates, *rates);
 	}
-	int_rate = (gint32)round (scale * rate);
+	int_rate = (gint32)rint (scale * rate);
 
 	*rates = g_list_append (*rates, GINT_TO_POINTER (int_rate));
 
