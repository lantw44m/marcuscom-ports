--- braille/libbrl/sercomm.c.orig	Mon Aug  2 13:13:53 2004
+++ braille/libbrl/sercomm.c	Tue Aug  3 14:49:40 2004
@@ -370,7 +370,7 @@
 static gboolean 
 brl_ser_glib_cb (GIOChannel   *source, 
 		 GIOCondition condition, 
-		 gpointer     data)
+		 gpointer     unused)
 {			
     gint n, i;
     guchar data[256];
