--- Src/DasherCore/DasherViewSquare.cpp.orig	2007-07-09 23:30:03.000000000 -0400
+++ Src/DasherCore/DasherViewSquare.cpp	2007-07-09 23:30:36.000000000 -0400
@@ -781,7 +781,7 @@ inline myint CDasherViewSquare::CustomID
   else
     return quot;
 #else
-  lldiv_t res = __gnu_cxx::lldiv(iNumerator, iDenominator);
+  lldiv_t res = lldiv(iNumerator, iDenominator);
   
   if(res.rem < 0)
     return res.quot - 1;
