--- battstat/battstat_applet.c.orig	Mon Aug 16 10:00:23 2004
+++ battstat/battstat_applet.c	Mon Aug 16 10:03:23 2004
@@ -349,7 +349,7 @@
 
 /* } */
 
-static char *get_remaining (apm_info apminfo)
+static char *get_remaining (struct apm_info apminfo)
 {
 	int time;
 	int hours;
