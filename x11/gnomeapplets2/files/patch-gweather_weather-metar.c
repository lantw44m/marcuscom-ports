--- gweather/weather-metar.c.orig	Tue Dec 21 18:41:39 2004
+++ gweather/weather-metar.c	Tue Dec 21 18:42:03 2004
@@ -8,6 +8,7 @@
 #  include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <regex.h>
 #include <gnome.h>
 #include "weather.h"
