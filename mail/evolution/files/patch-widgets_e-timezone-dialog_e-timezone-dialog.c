--- widgets/e-timezone-dialog/e-timezone-dialog.c.orig	2009-06-12 16:54:41.000000000 +0200
+++ widgets/e-timezone-dialog/e-timezone-dialog.c	2009-06-15 16:43:34.000000000 +0200
@@ -344,9 +344,20 @@ static icaltimezone*
 get_local_timezone(void)
 {
 	icaltimezone *zone;
+	long offset;
+#ifdef __BSD_VISIBLE
+	time_t tt;
+	struct tm tm;
+#endif
 
 	tzset();
-	zone =  icaltimezone_get_builtin_timezone_from_offset (-timezone, tzname[0]);
+#ifdef __BSD_VISIBLE
+	localtime_r (&tt, &tm);
+	offset = tm.tm_gmtoff;
+#else
+	offset = -timezone;
+#endif
+	zone =  icaltimezone_get_builtin_timezone_from_offset (offset, tzname[0]);
 
 	return zone;
 }
