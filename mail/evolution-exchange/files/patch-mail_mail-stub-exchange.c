--- mail/mail-stub-exchange.c.orig	Mon Aug  8 22:00:52 2005
+++ mail/mail-stub-exchange.c	Mon Aug  8 22:01:11 2005
@@ -2587,11 +2587,11 @@ subscribe_folder (MailStub *stub, const 
 static void
 unsubscribe_folder (MailStub *stub, const char *folder_name)
 {
-	d(printf ("unsubscribe folder : %s\n", folder_name));
 	MailStubExchange *mse = MAIL_STUB_EXCHANGE (stub);
 	ExchangeAccountFolderResult result;
 	EFolder *folder;
 	char *path, *pub_name;
+	d(printf ("unsubscribe folder : %s\n", folder_name));
 
 	path = g_build_filename ("/", folder_name, NULL);
 	folder = exchange_account_get_folder (mse->account, path);
