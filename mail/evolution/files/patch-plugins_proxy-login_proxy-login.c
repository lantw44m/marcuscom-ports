--- plugins/proxy-login/proxy-login.c.orig	Wed Jul 13 17:26:56 2005
+++ plugins/proxy-login/proxy-login.c	Wed Jul 13 17:27:15 2005
@@ -237,7 +237,6 @@ proxy_login_get_cnc (EAccount *account)
 {
 	EGwConnection *cnc;
 	CamelURL *url;
-	url = camel_url_new (account->source->url, NULL);
 	char *uri = NULL, *failed_auth = NULL, *key = NULL, *prompt = NULL, *password = NULL;
 	const char *use_ssl, *soap_port;
 
