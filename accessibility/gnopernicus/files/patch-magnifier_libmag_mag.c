--- magnifier/libmag/mag.c.orig	Sun May 11 23:07:48 2003
+++ magnifier/libmag/mag.c	Sun May 11 23:10:24 2003
@@ -647,7 +647,7 @@
 mag_zoomer_set_ZP_border_color (MagZoomer *mag_zoomer, 
 				gchar     *border_color)
 {
-	mag_zoomer->zoomer_placement.border.color = (gint32)atoll (border_color);
+	mag_zoomer->zoomer_placement.border.color = (gint32)strtoll (border_color, &border_color, 10);
 }
 
 /* __ MAG ZOOMERS CONTAINER ___________________________________________________*/
@@ -708,7 +708,7 @@
 {
     if (color)
     {
-	crosswire_color = (guint32)atoll(color);
+	crosswire_color = (guint32)strtoll(color, &color, 10);
 
 	if (cursor && crosswire)
 	    magnifier_set_crosswire_color (magnifier,
@@ -783,7 +783,7 @@
 {
     if (color)
     {
-	cursor_color = (guint32)atoll(color);
+	cursor_color = (guint32)strtoll(color, &color, 10);
 
 	if (cursor)
 	{
