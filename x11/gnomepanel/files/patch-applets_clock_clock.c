--- applets/clock/clock.c.orig	Thu Dec  4 17:57:00 2003
+++ applets/clock/clock.c	Wed Dec 10 23:23:38 2003
@@ -37,7 +37,9 @@
 #include <dirent.h>
 #include <string.h>
 #include <time.h>
+#ifdef HAVE_LANGINFO_H
 #include <langinfo.h>
+#endif
 
 #include <panel-applet.h>
 #include <panel-applet-gconf.h>
@@ -1117,7 +1119,11 @@
 {
 	const char *am;
 
+#ifdef HAVE_LANGINFO_H
 	am = nl_langinfo (AM_STR);
+#else
+	am = "AM";
+#endif
 	return (am[0] == '\0') ? CLOCK_FORMAT_24 : CLOCK_FORMAT_12;
 }
 
