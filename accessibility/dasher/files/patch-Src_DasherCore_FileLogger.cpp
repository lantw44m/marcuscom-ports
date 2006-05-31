--- Src/DasherCore/FileLogger.cpp.orig	Wed May 31 00:12:32 2006
+++ Src/DasherCore/FileLogger.cpp	Wed May 31 00:12:43 2006
@@ -538,7 +538,7 @@ std::string CFileLogger::GetTimeDateStam
 #ifdef _WIN32
         sprintf(strMs, "%d", sTimeBuffer.millitm);
 #else
-        sprintf(strMs, "%d", sTimeBuffer.tv_usec / 1000);
+        sprintf(strMs, "%d", (int) (sTimeBuffer.tv_usec / 1000));
 #endif
         if (strlen(strMs) == 1)
           strTimeStamp += "00";
