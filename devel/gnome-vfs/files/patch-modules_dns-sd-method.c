--- modules/dns-sd-method.c.orig	Sun Dec  4 16:49:28 2005
+++ modules/dns-sd-method.c	Sun Dec  4 16:51:37 2005
@@ -31,7 +31,9 @@
 
 #ifdef HAVE_AVAHI
 #include <avahi-client/client.h>
+#include <avahi-client/lookup.h>
 #include <avahi-common/error.h>
+#include <avahi-common/timeval.h>
 #include <avahi-common/simple-watch.h>
 #include <avahi-glib/glib-watch.h>
 #endif 
@@ -320,7 +322,7 @@ avahi_client_callback (AvahiClient *clie
 	AvahiSimplePoll *poll;
 
 	poll = user_data;
-	if (state == AVAHI_CLIENT_DISCONNECTED) {
+	if (state == AVAHI_CLIENT_FAILURE) {
 		avahi_simple_poll_quit (poll);
 	}
 }
@@ -333,12 +335,17 @@ local_browse_callback_sync (AvahiService
 			    const char *name,
 			    const char *type,
 			    const char *domain,
+			    AvahiLookupResultFlags flags,
 			    void *user_data)
 {
+	AvahiSimplePoll *poll = user_data;
+
 	if (event == AVAHI_BROWSER_NEW)
 		local_browse (TRUE, name, type, domain);
 	else if (event == AVAHI_BROWSER_REMOVE)
 		local_browse (FALSE, name, type, domain);
+	else if (event == AVAHI_BROWSER_ALL_FOR_NOW)
+		avahi_simple_poll_quit (poll);
 }
 
 static void
@@ -385,7 +392,7 @@ init_local (void)
 		}
 
 		poll = avahi_simple_poll_get (simple_poll);
-		client = avahi_client_new (poll, 
+		client = avahi_client_new (poll, 0,
 					   avahi_client_callback, simple_poll, &error);
 		
 		/* Check wether creating the client object succeeded */
@@ -400,7 +407,8 @@ init_local (void)
 		for (i = 0; i < G_N_ELEMENTS (dns_sd_types); i++) {
 			sb[i] = avahi_service_browser_new (client, AVAHI_IF_UNSPEC, AVAHI_PROTO_UNSPEC, 
 							   dns_sd_types[i].type, "local",
-							   local_browse_callback_sync, NULL);
+							   AVAHI_LOOKUP_USE_MULTICAST,
+							   local_browse_callback_sync, simple_poll);
 		}
 		
 
