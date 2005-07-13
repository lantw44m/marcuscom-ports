--- camel/camel-exchange-store.c.orig	Wed Jul 13 17:44:20 2005
+++ camel/camel-exchange-store.c	Wed Jul 13 17:45:09 2005
@@ -398,9 +398,9 @@ exchange_get_folder (CamelStore *store, 
 static gboolean
 exchange_folder_subscribed (CamelStore *store, const char *folder_name)
 {
-	d(printf ("is subscribed folder : %s\n", folder_name));
 	CamelExchangeStore *exch = CAMEL_EXCHANGE_STORE (store);
 	guint32 is_subscribed;
+	d(printf ("is subscribed folder : %s\n", folder_name));
 	
 	if (((CamelOfflineStore *) store)->state == CAMEL_OFFLINE_STORE_NETWORK_UNAVAIL) {
 		return;
@@ -421,8 +421,8 @@ static void
 exchange_subscribe_folder (CamelStore *store, const char *folder_name,
 				CamelException *ex)
 {
-	d(printf ("subscribe folder : %s\n", folder_name));
 	CamelExchangeStore *exch = CAMEL_EXCHANGE_STORE (store);
+	d(printf ("subscribe folder : %s\n", folder_name));
 	
 	if (((CamelOfflineStore *) store)->state == CAMEL_OFFLINE_STORE_NETWORK_UNAVAIL) {
 		camel_exception_set (ex, CAMEL_EXCEPTION_SYSTEM, _("Cannot subscribe folder in offline mode."));
@@ -438,8 +438,8 @@ static void
 exchange_unsubscribe_folder (CamelStore *store, const char *folder_name,
 				CamelException *ex)
 {
-	d(printf ("unsubscribe folder : %s\n", folder_name));
 	CamelExchangeStore *exch = CAMEL_EXCHANGE_STORE (store);
+	d(printf ("unsubscribe folder : %s\n", folder_name));
 	
 	if (((CamelOfflineStore *) store)->state == CAMEL_OFFLINE_STORE_NETWORK_UNAVAIL) {
 		camel_exception_set (ex, CAMEL_EXCEPTION_SYSTEM, _("Cannot unsubscribe folder in offline mode."));
@@ -475,9 +475,9 @@ static CamelFolderInfo *
 make_folder_info (CamelExchangeStore *exch, char *name, char *uri,
 		  int unread_count, int flags)
 {
-	d(printf ("make folder info : %s flags : %d\n", name, flags));
 	CamelFolderInfo *info;
 	const char *path;
+	d(printf ("make folder info : %s flags : %d\n", name, flags));
 
 	path = strstr (uri, "://");
 	if (!path)
