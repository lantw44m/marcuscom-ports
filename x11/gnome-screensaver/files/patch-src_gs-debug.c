--- src/gs-debug.c.orig	Tue Jun 13 15:18:14 2006
+++ src/gs-debug.c	Tue Jun 13 15:21:32 2006
@@ -132,9 +132,13 @@ _gs_profile_log (const char *func,
         char   *str;
         char   *formatted;
 
-        va_start (args, format);
-        formatted = g_strdup_vprintf (format, args);
-        va_end (args);
+	if (format == NULL)
+		formatted = g_strdup ("");
+	else {
+        	va_start (args, format);
+        	formatted = g_strdup_vprintf (format, args);
+        	va_end (args);
+	}
 
         if (func != NULL) {
                 str = g_strdup_printf ("MARK: %s %s: %s %s", g_get_prgname(), func, note ? note : "", formatted);
