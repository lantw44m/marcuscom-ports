--- embed/mozilla/GlobalHistory.cpp.orig	Sun Feb 15 14:52:36 2004
+++ embed/mozilla/GlobalHistory.cpp	Sun Feb 15 14:54:18 2004
@@ -30,13 +30,15 @@
 #include <nsString.h>
 #include <nsIURI.h>
 
-NS_IMPL_ISUPPORTS2(MozGlobalHistory,
 #if MOZILLA_SNAPSHOT > 13
-		   nsIGlobalHistory2,
+NS_IMPL_ISUPPORTS2(MozGlobalHistory,
+	nsIGlobalHistory2,
+	nsIBrowserHistory)
 #else
+NS_IMPL_ISUPPORTS2(MozGlobalHistory,
 		   nsIGlobalHistory,
-#endif
 		   nsIBrowserHistory)
+#endif
 
 MozGlobalHistory::MozGlobalHistory ()
 {
