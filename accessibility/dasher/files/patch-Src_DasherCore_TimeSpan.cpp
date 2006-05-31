--- Src/DasherCore/TimeSpan.cpp.orig	Wed May 31 00:14:59 2006
+++ Src/DasherCore/TimeSpan.cpp	Wed May 31 00:15:07 2006
@@ -134,7 +134,7 @@ string CTimeSpan::GetTimeStamp()
 #ifdef _WIN32
     sprintf(szMs, "%d", sTimeBuffer.millitm);
 #else
-    sprintf(szMs, "%d", sTimeBuffer.tv_usec / 1000);
+    sprintf(szMs, "%d", (int) (sTimeBuffer.tv_usec / 1000));
 #endif
     if (strlen(szMs) == 1)
       strTimeStamp += "00";
