--- braille/libbrl/sercomm.c.orig	Tue Aug  3 11:12:04 2004
+++ braille/libbrl/sercomm.c	Tue Aug  3 11:17:36 2004
@@ -370,10 +370,9 @@
 static gboolean 
 brl_ser_glib_cb (GIOChannel   *source, 
 		 GIOCondition condition, 
-		 gpointer     data)
+		 guchar       *data)
 {			
     gint n, i;
-    guchar data[256];
 	
     if (!glib_poll) 
 	return FALSE;
