$FreeBSD: ports/java/jdk13/files/patch-nsCOMPtr.h,v 1.1 2004/08/31 19:52:25 glewis Exp $

--- ../ext/plugin/oji-plugin/include/solaris/navig5/nsCOMPtr.h	11 Jul 2001 21:45:15 -0000	1.1.1.1
+++ ../ext/plugin/oji-plugin/include/solaris/navig5/nsCOMPtr.h	30 Aug 2004 06:21:43 -0000
@@ -600,7 +600,7 @@
     Specializing |nsCOMPtr| for |nsISupports| allows us to 
   */
 
-// template <>
+template <>
 class nsCOMPtr<nsISupports>
     : private nsCOMPtr_base
   {
@@ -843,7 +843,7 @@
   };
 
 
-// template <>
+template <>
 class nsGetterAddRefs<nsISupports>
   {
     public:
