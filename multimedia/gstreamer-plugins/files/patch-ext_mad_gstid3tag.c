--- ext/mad/gstid3tag.c.orig	Fri Dec 19 15:09:09 2003
+++ ext/mad/gstid3tag.c	Fri Dec 19 15:09:33 2003
@@ -474,8 +474,9 @@
 	  tmp = strtoul (utf8, &check, 10);
 	  if (*check != '\0') break;
 	  if (strcmp (tag_name, GST_TAG_DATE) == 0) {
+	    GDate *d;
 	    if (tmp == 0) break;
-	    GDate *d = g_date_new_dmy (1, 1, tmp);
+	    d = g_date_new_dmy (1, 1, tmp);
 	    tmp = g_date_get_julian (d);
 	    g_date_free (d);
 	  }
