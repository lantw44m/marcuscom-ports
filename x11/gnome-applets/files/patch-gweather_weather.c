--- gweather/weather.c.orig	Mon Dec  8 12:47:00 2003
+++ gweather/weather.c	Mon Dec  8 12:50:03 2003
@@ -1915,7 +1915,7 @@
       degree = "F";
       
    g_snprintf(buf, sizeof (buf), "%d\302\260%s",
-	      (int)lrint(info->temp), degree);
+	      (int)rint(info->temp), degree);
     
     return buf;
 }
