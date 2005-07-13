--- mail/mail-stub-exchange.c.orig	Wed Jul 13 17:45:44 2005
+++ mail/mail-stub-exchange.c	Wed Jul 13 17:46:22 2005
@@ -2508,12 +2508,12 @@ subscribe_folder (MailStub *stub, const 
 static void
 unsubscribe_folder (MailStub *stub, const char *folder_name)
 {
-	d(printf ("unsubscribe folder : %s\n", folder_name));
 	MailStubExchange *mse = MAIL_STUB_EXCHANGE (stub);
 	ExchangeAccountFolderResult result;
 	EFolder *folder;
 	char *path;
 	const char *folder_type, *physical_uri;
+	d(printf ("unsubscribe folder : %s\n", folder_name));
 
 	path = g_build_filename ("/", folder_name, NULL);
 	folder = exchange_account_get_folder (mse->account, path);
