--- extensions/popup-blocker/mozilla/PopupBlockerListener.cpp.orig	Sun Mar  7 20:06:38 2004
+++ extensions/popup-blocker/mozilla/PopupBlockerListener.cpp	Mon Mar  8 01:36:08 2004
@@ -62,6 +62,7 @@
 	rv = popupWindowURI->GetSpec (popupWindowURIString);
 	NS_ENSURE_SUCCESS (rv, NS_ERROR_FAILURE);
 
+#if MOZILLA_SNAPSHOT >= 14
 	nsAutoString popupWindowFeatures;
 	rv = popupEvent->GetPopupWindowFeatures (popupWindowFeatures);
 	NS_ENSURE_SUCCESS (rv, NS_ERROR_FAILURE);
@@ -69,6 +70,10 @@
 	ephy_popup_blocker_extension_block (mOwner,
 					    popupWindowURIString.get (),
 					    NS_ConvertUCS2toUTF8 (popupWindowFeatures).get ());
+#else
+	ephy_popup_blocker_extension_block (mOwner, popupWindowURIString.get (),
+		NULL);
+#endif
 }
 
 nsresult
