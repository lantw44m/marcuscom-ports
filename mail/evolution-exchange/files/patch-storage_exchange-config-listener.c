--- storage/exchange-config-listener.c.orig	Tue Aug 23 20:19:24 2005
+++ storage/exchange-config-listener.c	Tue Aug 23 20:19:37 2005
@@ -253,9 +253,10 @@ migrate_account_esource (EAccount *accou
 void
 exchange_config_listener_migrate_esources (ExchangeConfigListener *config_listener)
 {
+	EAccount *account;
 	g_return_if_fail (config_listener != NULL);
 
-	EAccount *account = config_listener->priv->configured_account;
+	account = config_listener->priv->configured_account;
 
 	migrate_account_esource (account, EXCHANGE_CALENDAR_FOLDER);
 	migrate_account_esource (account, EXCHANGE_TASKS_FOLDER);
