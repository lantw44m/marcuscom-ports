--- camel/providers/imap4/camel-imap4-store.c.orig	Mon May  7 00:57:52 2007
+++ camel/providers/imap4/camel-imap4-store.c	Mon May  7 00:58:34 2007
@@ -324,7 +324,7 @@ connect_to_server (CamelIMAP4Engine *eng
 	
 	camel_imap4_command_unref (ic);
 	
-	if (camel_tcp_stream_ssl_enable_ssl ((SpruceTcpStreamSSL *) tcp_stream) == -1) {
+	if (camel_tcp_stream_ssl_enable_ssl (CAMEL_TCP_STREAM_SSL (tcp_stream)) == -1) {
 		camel_exception_setv (ex, CAMEL_EXCEPTION_SYSTEM,
 				      _("Failed to connect to IMAP server %s in secure mode: %s"),
 				      service->url->host, _("TLS negotiations failed"));
