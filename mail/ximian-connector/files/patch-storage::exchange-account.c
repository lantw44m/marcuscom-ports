--- storage/exchange-account.c.orig	Mon Aug 16 19:46:00 2004
+++ storage/exchange-account.c	Mon Aug 16 19:52:26 2004
@@ -800,7 +800,7 @@
 		password = e_passwords_ask_password (
 			_("Enter password"),
 			"Exchange", account->priv->password_key,
-			prompt, TRUE, E_PASSWORDS_REMEMBER_FOREVER,
+			prompt, E_PASSWORDS_REMEMBER_FOREVER,
 			&remember, NULL);
 		if (remember != oldremember) {
 			account->priv->account->source->save_passwd = remember;
