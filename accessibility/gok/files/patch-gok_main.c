--- gok/main.c.orig	Thu Jun 10 14:28:54 2004
+++ gok/main.c	Thu Jun 10 14:30:28 2004
@@ -584,8 +584,9 @@
 		
 		fprintf (stderr, "\nGOK Actions:\n");
 		if (error == NULL) {
+			GSList* listhead;
 			list = g_slist_sort (list, (GCompareFunc)comparebasenames);
-			GSList* listhead = list;
+			listhead = list;
 			while (list) {
 				fprintf(stderr,"%s\n",g_path_get_basename(list->data));
 				g_free(list->data);
@@ -612,8 +613,9 @@
 		fprintf (stderr, "\nGOK Access Methods:\n");
 		if (error == NULL) {
 			gchar* base;
+			GSList* listhead;
 			list = g_slist_sort (list, (GCompareFunc)comparebasenames);
-			GSList* listhead = list;
+			listhead = list;
 			while (list) {
 				base = g_path_get_basename(list->data);
 				fprintf(stderr,"%s\n",base);
