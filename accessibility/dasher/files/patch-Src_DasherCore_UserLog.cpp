--- Src/DasherCore/UserLog.cpp.orig	Wed May 31 00:15:35 2006
+++ Src/DasherCore/UserLog.cpp	Wed May 31 00:16:03 2006
@@ -881,7 +881,7 @@ bool CUserLog::UpdateMouseLocation()
   double dTime = (sTimeBuffer.time * 1000.0) + sTimeBuffer.millitm;
 #else
   gettimeofday(&sTimeBuffer, &sTimezoneBuffer);
-  double dTime = (sTimeBuffer.tv_sec * 1000.0) + sTimeBuffer.tv_usec / 1000;
+  double dTime = (sTimeBuffer.tv_sec * 1000.0) + (int) (sTimeBuffer.tv_usec / 1000);
 #endif
 
   
