--- embed/mozilla/GtkNSSKeyPairDialogs.cpp.orig	Tue Jun 29 16:51:48 2004
+++ embed/mozilla/GtkNSSKeyPairDialogs.cpp	Tue Jun 29 16:52:26 2004
@@ -91,7 +91,7 @@
 	NS_DECL_ISUPPORTS
 	NS_DECL_NSIDOMWINDOWINTERNAL
 	NS_DECL_NSIDOMWINDOW
-#if MOZILLA_SNAPSHOT >= 19
+#if MOZILLA_SNAPSHOT >= 16
 	NS_DECL_NSIDOMWINDOW2
 #endif
 
@@ -101,7 +101,7 @@
 	gboolean close_called;
 };
 
-#if MOZILLA_SNAPSHOT >= 19
+#if MOZILLA_SNAPSHOT >= 16
 NS_IMPL_ISUPPORTS3(KeyPairHelperWindow, nsIDOMWindowInternal, nsIDOMWindow, nsIDOMWindow2)
 #else
 NS_IMPL_ISUPPORTS2(KeyPairHelperWindow, nsIDOMWindowInternal, nsIDOMWindow)
@@ -249,7 +249,7 @@
     MOZ_NOT_IMPLEMENTED
 }
 
-#if MOZILLA_SNAPSHOT >= 19
+#if MOZILLA_SNAPSHOT >= 16
 NS_IMETHODIMP KeyPairHelperWindow::GetWindowRoot(nsIDOMEventTarget * *aEvent)
 {
     MOZ_NOT_IMPLEMENTED
