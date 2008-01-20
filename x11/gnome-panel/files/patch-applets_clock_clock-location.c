--- applets/clock/clock-location.c.orig	2008-01-20 00:04:16.000000000 -0600
+++ applets/clock/clock-location.c	2008-01-20 00:05:33.000000000 -0600
@@ -28,6 +28,8 @@
 #include "set-timezone.h"
 #include "gweather-xml.h"
 
+#define daylight 1
+
 G_DEFINE_TYPE (ClockLocation, clock_location, G_TYPE_OBJECT)
 
 typedef struct {
