--- gweather/gweather-pref.c.orig	Mon Jul 19 18:24:06 2004
+++ gweather/gweather-pref.c	Mon Jul 19 18:28:39 2004
@@ -411,13 +411,14 @@
         }
     }
     if (!prefs->temperature_unit || prefs->temperature_unit == TEMP_UNIT_DEFAULT ) {
+#ifdef _NL_MEASUREMENT_MEASUREMENT
         imperial = nl_langinfo(_NL_MEASUREMENT_MEASUREMENT);
         if ( imperial && imperial[0] == 2 )  {
             /* imperial */
             prefs->temperature_unit = TEMP_UNIT_FAHRENHEIT;
-        } else {
+        } else
+#endif
             prefs->temperature_unit = TEMP_UNIT_CENTIGRADE;
-        }
     }
 }
 
@@ -446,13 +447,14 @@
         }
     }
     if ( (!prefs->speed_unit) || prefs->speed_unit == SPEED_UNIT_DEFAULT ) {
+#ifdef _NL_MEASUREMENT_MEASUREMENT
         imperial = nl_langinfo(_NL_MEASUREMENT_MEASUREMENT);
         if ( imperial && imperial[0] == 2 )  {
             /* imperial */
             prefs->speed_unit = SPEED_UNIT_KNOTS;
-        } else {
+        } else
+#endif
             prefs->speed_unit = SPEED_UNIT_MS;
-        }
     }
 }
 
@@ -483,13 +485,14 @@
         }
     }
     if ( (!prefs->pressure_unit) || prefs->pressure_unit == PRESSURE_UNIT_DEFAULT ) {
+#ifdef _NL_MEASUREMENT_MEASUREMENT
         imperial = nl_langinfo(_NL_MEASUREMENT_MEASUREMENT);
         if ( imperial && imperial[0] == 2 )  {
             /* imperial */
             prefs->pressure_unit = PRESSURE_UNIT_INCH_HG;
-        } else {
+        } else
+#endif
             prefs->pressure_unit = PRESSURE_UNIT_HPA;
-        }
     }	
 }
 
@@ -518,13 +521,14 @@
     }
 
 	if ((!prefs->distance_unit) || prefs->distance_unit == DISTANCE_UNIT_DEFAULT ) {
+#ifdef _NL_MEASUREMENT_MEASUREMENT
         imperial = nl_langinfo(_NL_MEASUREMENT_MEASUREMENT);
         if ( imperial && imperial[0] == 2 )  {
             /* imperial */
             prefs->distance_unit = DISTANCE_UNIT_MILES;
-        } else {
+        } else
+#endif
             prefs->distance_unit = DISTANCE_UNIT_METERS;
-        }
     }
 
     return;
