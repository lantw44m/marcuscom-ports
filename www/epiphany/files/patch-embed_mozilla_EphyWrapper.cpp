--- embed/mozilla/EphyWrapper.cpp.orig	Fri Oct 17 18:57:27 2003
+++ embed/mozilla/EphyWrapper.cpp	Sun Nov 30 18:57:18 2003
@@ -74,6 +74,7 @@
 #include "nsIPresContext.h"
 #include "nsIAtom.h"
 #include "nsIDocumentCharsetInfo.h"
+#include "nsPromiseFlatString.h"
 #include "ContentHandler.h"
 #include "EphyEventListener.h"
 
@@ -590,8 +591,13 @@
 	nsCOMPtr<nsIDocument> doc = do_QueryInterface(DOMDocument);
 	if(!doc) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 11
+	nsIURI *uri;
+	uri = doc->GetDocumentURL ();
+#else
 	nsCOMPtr<nsIURI> uri;
 	doc->GetDocumentURL(getter_AddRefs(uri));
+#endif
 
 	return uri->GetSpec (url);
 }
@@ -608,8 +614,13 @@
         nsCOMPtr<nsIDocument> doc = do_QueryInterface(DOMDocument);
         if(!doc) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 11
+	nsIURI *uri;
+	uri = doc->GetDocumentURL ();
+#else
         nsCOMPtr<nsIURI> uri;
         doc->GetDocumentURL(getter_AddRefs(uri));
+#endif
 
         uri->GetSpec (url);
 
@@ -773,23 +784,13 @@
 	info = g_new0 (EphyEncodingInfo, 1);
 	*infoptr = info;
 
-#if MOZILLA_SNAPSHOT >= 10
-	nsCAutoString enc;	
-	result = doc->GetDocumentCharacterSet (enc);
-	if (NS_FAILED (result)) return NS_ERROR_FAILURE;
-
-	info->encoding = g_strdup (enc.get());
-#else
-	nsAutoString enc;
-	result = doc->GetDocumentCharacterSet (enc);
-	if (NS_FAILED (result)) return NS_ERROR_FAILURE;
-
-	info->encoding = g_strdup (NS_ConvertUCS2toUTF8(enc).get());
-#endif
-
 	PRInt32 source;
+#if MOZILLA_SNAPSHOT > 11
+	source = doc->GetDocumentCharacterSetSource ();
+#else
 	result = doc->GetDocumentCharacterSetSource (&source);
 	if (NS_FAILED (result)) return NS_ERROR_FAILURE;
+#endif
 	info->encoding_source = (EphyEncodingSource) source;
 
 	nsCOMPtr<nsIDocShell> ds;
@@ -831,7 +832,27 @@
 								  &result);
 	if (NS_FAILED(result) || !mdv) return NS_ERROR_FAILURE;
 
+#if MOZILLA_SNAPSHOT > 11
+	const nsACString& charsetEnc = doc->GetDocumentCharacterSet ();
+	if (charsetEnc.IsEmpty()) return NS_ERROR_FAILURE;
+
+	info->encoding = g_strdup (PromiseFlatCString(charsetEnc).get());
+#elif MOZILLA_SNAPSHOT >= 10
+	nsCAutoString charsetEnc;	
+	result = doc->GetDocumentCharacterSet (charsetEnc);
+	if (NS_FAILED (result)) return NS_ERROR_FAILURE;
+
+	info->encoding = g_strdup (charsetEnc.get());
+#else
+	nsAutoString charsetEnc;
+	result = doc->GetDocumentCharacterSet (charsetEnc);
+	if (NS_FAILED (result)) return NS_ERROR_FAILURE;
+
+	info->encoding = g_strdup (NS_ConvertUCS2toUTF8(charsetEnc).get());
+#endif
+
 #if MOZILLA_SNAPSHOT >= 10
+	nsCAutoString enc;
 	result = mdv->GetDefaultCharacterSet (enc);
 	if (NS_FAILED (result)) return NS_ERROR_FAILURE;
 	info->default_encoding = g_strdup (enc.get());
