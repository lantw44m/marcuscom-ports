--- src/sharp/datetime.cpp.orig	2009-12-28 12:46:01.000000000 +0100
+++ src/sharp/datetime.cpp	2010-01-02 22:05:18.000000000 +0100
@@ -83,14 +83,14 @@ namespace sharp {
   int DateTime::year() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_year + 1900;
   }
 
   int DateTime::day_of_year() const
   {
     struct tm result;
-    localtime_r(&m_date.tv_sec, &result);
+    localtime_r((const time_t *)&m_date.tv_sec, &result);
     return result.tm_yday;
   }
 
@@ -109,14 +109,14 @@ namespace sharp {
   std::string DateTime::to_string(const char * format) const
   {
     struct tm result; 
-    return _to_string(format, localtime_r(&m_date.tv_sec, &result));
+    return _to_string(format, localtime_r((const time_t *)&m_date.tv_sec, &result));
   }
 
 
   std::string DateTime::to_short_time_string() const
   {
     struct tm result;
-    return _to_string("%R", localtime_r(&m_date.tv_sec, &result));
+    return _to_string("%R", localtime_r((const time_t *)&m_date.tv_sec, &result));
   }
 
   std::string DateTime::to_iso8601() const
