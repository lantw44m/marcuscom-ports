--- gweather/weather.c.orig	Mon Jul 19 18:29:38 2004
+++ gweather/weather.c	Mon Jul 19 18:30:13 2004
@@ -2264,11 +2264,12 @@
 const gchar *weather_info_get_humidity (WeatherInfo *info)
 {
     static gchar buf[20];
+    gdouble humidity;
     g_return_val_if_fail(info != NULL, NULL);
     if (!info->valid)
         return "-";
 
-    gdouble humidity = calc_humidity(info->temp, info->dew);
+    humidity = calc_humidity(info->temp, info->dew);
     if (humidity < 0.0)
         return _("Unknown");
 
@@ -2279,11 +2280,12 @@
 
 const gchar *weather_info_get_apparent (WeatherInfo *info)
 {
+    gdouble apparent;
     g_return_val_if_fail(info != NULL, NULL);
     if (!info->valid)
         return "-";
 
-    gdouble apparent = calc_apparent(info);
+    apparent = calc_apparent(info);
     if (apparent < -500.0)
         return _("Unknown");
     
