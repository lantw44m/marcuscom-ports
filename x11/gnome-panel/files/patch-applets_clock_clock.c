--- applets/clock/clock.c.orig	2008-01-20 00:03:54.000000000 -0600
+++ applets/clock/clock.c	2008-01-20 00:04:46.000000000 -0600
@@ -84,6 +84,8 @@
 
 #define FALLBACK_CONFIG_TOOL "time-admin"
 
+#define daylight 1
+
 static const char *clock_config_tools [] = {
 	CLOCK_TIME_UTILITY,
 	FALLBACK_CONFIG_TOOL
