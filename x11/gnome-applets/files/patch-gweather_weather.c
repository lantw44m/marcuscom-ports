--- gweather/weather.c.orig	Tue Nov 30 02:37:42 2004
+++ gweather/weather.c	Tue Nov 30 02:42:17 2004
@@ -20,7 +20,9 @@
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
+#ifndef __FreeBSD__
 #include <values.h>
+#endif
 
 #ifdef __FreeBSD__
 #include <sys/types.h>
@@ -113,6 +115,7 @@
 				       const gchar *zone, const gchar *radar, const gchar *coordinates)
 {
     WeatherLocation *location;
+    char lat[12], lon[12];
 
     location = g_new(WeatherLocation, 1);
   
@@ -145,7 +148,6 @@
         location->zone_valid = TRUE;
     }
 
-    char lat[12], lon[12];
     if (coordinates && sscanf(coordinates, "%s %s", lat, lon) == 2) {
         location->coordinates = g_strdup(coordinates);
         location->latitude = dmsh2rad (lat);
@@ -871,6 +873,18 @@
     time_t gm_midn;
     time_t lcl_midn;
     gdouble gm_hoff;
+    gdouble ndays;
+    gdouble meanAnom;
+    gdouble eccenAnom;
+    gdouble delta;
+    gdouble lambda;
+    gdouble ra1, ra2, decl1, decl2;
+    gdouble rise1, rise2, set1, set2;
+    gdouble tt;
+    gdouble t00;
+    gdouble x;
+    gdouble u;
+    gdouble dt;
     
     /* Approximate preceding local midnight at observer's longitude */
     gm_midn = t - (t % 86400);
@@ -885,17 +899,17 @@
      * Ecliptic longitude of the sun at midnight local time
      * Start with an estimate based on a fixed daily rate
      */
-    gdouble ndays = EPOCH_TO_J2000(lcl_midn) / 86400.;
-    gdouble meanAnom = DEGREES_TO_RADIANS(ndays * SOL_PROGRESSION
+    ndays = EPOCH_TO_J2000(lcl_midn) / 86400.;
+    meanAnom = DEGREES_TO_RADIANS(ndays * SOL_PROGRESSION
 					  + MEAN_ECLIPTIC_LONGITUDE - PERIGEE_LONGITUDE);
     
     /*
      * Approximate solution of Kepler's equation:
      * Find E which satisfies  E - e sin(E) = M (mean anomaly)
      */
-    gdouble eccenAnom = meanAnom;
-    gdouble delta;
-    gdouble lambda;
+    eccenAnom = meanAnom;
+    delta;
+    lambda;
     
     while (1e-12 < fabs( delta = eccenAnom - ECCENTRICITY * sin(eccenAnom) - meanAnom))
     {
@@ -910,7 +924,6 @@
     
     /* Calculate equitorial coordinates of sun at previous and next local midnights */
 
-    gdouble ra1, ra2, decl1, decl2;
     
     ecl2equ (lcl_midn, lambda, &ra1, &decl1);
     ecl2equ (lcl_midn + 86400., lambda + DEGREES_TO_RADIANS(SOL_PROGRESSION), &ra2, &decl2);
@@ -920,7 +933,6 @@
      * between the two
      */
 
-    gdouble rise1, rise2, set1, set2;
     gstObsv (ra1, decl1, obsLat, obsLon - (gm_hoff * M_PI / 12.), &rise1, &set1);
     gstObsv (ra2, decl2, obsLat, obsLon - (gm_hoff * M_PI / 12.), &rise2, &set2);
     
@@ -928,8 +940,8 @@
     if (isnan(rise1) || isnan(rise2))
         return FALSE;
 
-    gdouble tt = t0(lcl_midn);
-    gdouble t00 = tt - (gm_hoff + RADIANS_TO_HOURS(obsLon)) * 1.002737909;
+    tt = t0(lcl_midn);
+    t00 = tt - (gm_hoff + RADIANS_TO_HOURS(obsLon)) * 1.002737909;
 
     if (t00 < 0.)
 	t00 += 24.;
@@ -950,9 +962,9 @@
     set1 = (24.07 * set1 - t00 * (set2 - set1)) / (24.07 + set1 - set2);
 
     decl2 = (decl1 + decl2) / 2.;
-    gdouble x = DEGREES_TO_RADIANS(0.830725);
-    gdouble u = acos ( sin(obsLat) / cos(decl2) );
-    gdouble dt =  RADIANS_TO_HOURS ( asin ( sin(x) / sin(u) )
+    x = DEGREES_TO_RADIANS(0.830725);
+    u = acos ( sin(obsLat) / cos(decl2) );
+    dt =  RADIANS_TO_HOURS ( asin ( sin(x) / sin(u) )
 				     / cos(decl2) );
     
     rise1 = (rise1 - dt - tt) * 0.9972695661;
@@ -2821,8 +2833,9 @@
                 }
         } else {
 	    time_t current_time;
+	    gboolean useSun;
 	    current_time = time (NULL);
-	    gboolean useSun = (! info->sunValid )
+	    useSun = (! info->sunValid )
 	                      || (current_time >= info->sunrise &&
 				  current_time < info->sunset);
             switch (sky) {
