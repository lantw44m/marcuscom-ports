--- libgswitchit/gswitchit_util.c.orig	Mon Dec 13 01:09:01 2004
+++ libgswitchit/gswitchit_util.c	Mon Dec 13 01:15:31 2004
@@ -60,7 +60,7 @@
 		      int level, const char format[], va_list args)
 {
 	time_t now = time (NULL);
-	g_log (NULL, G_LOG_LEVEL_DEBUG, "[%08ld,%03d,%s:%s/] \t", now,
+	g_log (NULL, G_LOG_LEVEL_DEBUG, "[%08ld,%03d,%s:%s/] \t", (long) now,
 	       level, file, function);
 	g_logv (NULL, G_LOG_LEVEL_DEBUG, format, args);
 }
