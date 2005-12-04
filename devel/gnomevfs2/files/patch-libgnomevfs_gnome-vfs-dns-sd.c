--- libgnomevfs/gnome-vfs-dns-sd.c	2005/11/14 11:41:13	1.16
+++ libgnomevfs/gnome-vfs-dns-sd.c	2005/11/22 10:55:30	1.18
@@ -36,6 +36,15 @@
 #include <gconf/gconf-client.h>
 #include <unistd.h>
 
+#ifdef HAVE_AVAHI
+#include <avahi-client/client.h>
+#include <avahi-client/lookup.h>
+#include <avahi-common/error.h>
+#include <avahi-common/simple-watch.h>
+#include <avahi-common/timeval.h>
+#include <avahi-glib/glib-watch.h>
+#endif 
+
 #ifdef HAVE_HOWL
 /* Need to work around howl exporting its config file... */
 #undef PACKAGE
@@ -722,6 +731,60 @@
 
 /* multicast DNS functions */
 
+#ifdef HAVE_AVAHI
+static AvahiClient *global_client = NULL;
+static gboolean avahi_initialized = FALSE;
+
+static AvahiClient *get_global_avahi_client (void);
+
+/* Callback for state changes on the Client */
+static void
+avahi_client_callback (AvahiClient *client, AvahiClientState state, void *userdata)
+{
+	if (state == AVAHI_CLIENT_FAILURE) {
+		if (avahi_client_errno (client) == AVAHI_ERR_DISCONNECTED) {
+			/* Destroy old client */
+			avahi_client_free (client);
+			global_client = NULL;
+			avahi_initialized = FALSE;
+
+			/* Reconnect */
+			get_global_avahi_client ();
+		}
+	}
+}
+
+static AvahiClient *
+get_global_avahi_client (void) {
+	static AvahiGLibPoll *glib_poll = NULL;
+	int error;
+
+	if (!avahi_initialized) {
+		if (glib_poll == NULL) {
+			glib_poll = avahi_glib_poll_new (NULL, G_PRIORITY_DEFAULT);
+		}
+
+		/* Create a new AvahiClient instance */
+		global_client = avahi_client_new (avahi_glib_poll_get (glib_poll),
+						  AVAHI_CLIENT_NO_FAIL,
+						  avahi_client_callback,
+						  glib_poll,
+						  &error);
+
+		if (global_client == NULL) {    
+			/* Print out the error string */
+			g_warning ("Error initializing Avahi: %s", avahi_strerror (error));
+			avahi_glib_poll_free (glib_poll);
+			glib_poll = NULL;
+			return NULL;
+		}
+		avahi_initialized = TRUE;
+	}
+
+	return global_client;
+}
+#endif
+
 #ifdef HAVE_HOWL
 
 static gboolean
@@ -788,6 +851,10 @@
 
 	/* multicast: */
 
+#ifdef HAVE_AVAHI
+	AvahiServiceBrowser *avahi_sb;
+#endif
+
 #ifdef HAVE_HOWL
 	sw_discovery_oid howl_id;
 #endif
@@ -864,6 +931,41 @@
 	return NULL;
 }
 
+#ifdef HAVE_AVAHI
+static void 
+avahi_browse_callback (AvahiServiceBrowser *b,
+		       AvahiIfIndex interface,
+		       AvahiProtocol protocol,
+		       AvahiBrowserEvent event,
+		       const char *name,
+		       const char *type,
+		       const char *domain,
+		       AvahiLookupResultFlags flags,
+		       void *userdata)
+{
+	GnomeVFSDNSSDBrowseHandle *handle;
+	GnomeVFSDNSSDService service;
+	handle = userdata;
+    
+	service.name = (char *)name;
+	service.type = (char *)type;
+	service.domain = (char *)domain;
+	
+	if (event == AVAHI_BROWSER_FAILURE ||
+	    event == AVAHI_BROWSER_ALL_FOR_NOW ||
+	    event == AVAHI_BROWSER_CACHE_EXHAUSTED) {
+		return;
+	}
+	
+	if (!handle->cancelled) {
+		handle->callback (handle,
+				  (event == AVAHI_BROWSER_NEW) ? GNOME_VFS_DNS_SD_SERVICE_ADDED : GNOME_VFS_DNS_SD_SERVICE_REMOVED,
+				  &service,
+				  handle->callback_data);
+	}
+}
+#endif
+
 #ifdef HAVE_HOWL
 
 struct howl_browse_idle_data {
@@ -1012,7 +1114,25 @@
 	handle->callback_data_destroy_func = callback_data_destroy_func;
 	
 	if (strcmp (domain, "local") == 0) {
-#ifdef HAVE_HOWL
+#ifdef HAVE_AVAHI
+		AvahiClient *client;
+		AvahiServiceBrowser *sb;
+
+		handle->is_local = TRUE;
+		client = get_global_avahi_client ();
+		if (client) {
+			sb = avahi_service_browser_new (client, AVAHI_IF_UNSPEC, AVAHI_PROTO_UNSPEC, type, NULL, 
+							AVAHI_LOOKUP_USE_MULTICAST,
+							avahi_browse_callback, handle);
+			if (sb != NULL) {
+				handle->avahi_sb = sb;
+				*handle_out = handle;
+				return GNOME_VFS_OK;
+			}
+			g_warning ("Failed to create service browser: %s\n", avahi_strerror( avahi_client_errno (client)));
+		}
+		return GNOME_VFS_ERROR_GENERIC;
+#elif defined (HAVE_HOWL)
 		sw_result res;
 		sw_discovery session;
 		
@@ -1063,6 +1183,11 @@
 gnome_vfs_dns_sd_stop_browse (GnomeVFSDNSSDBrowseHandle *handle)
 {
 	if (handle->is_local) {
+#ifdef HAVE_AVAHI
+		handle->cancelled = TRUE;
+		avahi_service_browser_free (handle->avahi_sb);
+		free_browse_handle (handle);
+#endif
 #ifdef HAVE_HOWL
 		handle->cancelled = TRUE;
 		sw_discovery_cancel (get_global_howl_session (), handle->howl_id);
@@ -1093,6 +1218,10 @@
 	int text_len;
 	
 	/* multicast: */
+#ifdef HAVE_AVAHI
+	AvahiServiceResolver *avahi_sr;
+#endif
+
 #ifdef HAVE_HOWL
 	sw_discovery_oid howl_id;
 	guint timeout_tag;
@@ -1174,6 +1303,71 @@
 	return NULL;
 }
 
+#ifdef HAVE_AVAHI
+static void
+avahi_resolve_async_callback (AvahiServiceResolver *r,
+			      AvahiIfIndex interface,
+			      AvahiProtocol protocol,
+			      AvahiResolverEvent event,
+			      const char *name,
+			      const char *type,
+			      const char *domain,
+			      const char *host_name,
+			      const AvahiAddress *address,
+			      uint16_t port,
+			      AvahiStringList *txt,
+			      AvahiLookupResultFlags flags,
+			      void *user_data)
+{
+	GnomeVFSDNSSDResolveHandle *handle;
+	GnomeVFSDNSSDService service;
+	GHashTable *hash;
+	size_t text_len;
+	char *text;
+	char host[128];
+
+	handle = user_data;
+	if (event == AVAHI_RESOLVER_FOUND) {
+		text_len = avahi_string_list_serialize (txt, NULL, 0);
+		text = g_malloc (text_len);
+		text_len = avahi_string_list_serialize (txt, text, text_len);
+
+		hash = decode_txt_record (text, text_len);
+
+		service.name = (char *)name;
+		service.type = (char *)type;
+		service.domain = (char *)domain;
+		
+		avahi_address_snprint (host, sizeof(host), address);
+		handle->callback (handle,
+				  GNOME_VFS_OK,
+				  &service,
+				  host,
+				  port,
+				  hash,
+				  handle->text_len,
+				  handle->text,
+				  handle->callback_data);
+		if (hash) {
+			g_hash_table_destroy (hash);
+		}
+		g_free (text);
+
+	} else if (event == AVAHI_RESOLVER_FAILURE) {
+		handle->callback (handle,
+				  GNOME_VFS_ERROR_HOST_NOT_FOUND,
+				  NULL,
+				  NULL, 0,
+				  NULL, 0, NULL,
+				  handle->callback_data);
+	}
+	
+	avahi_service_resolver_free (r);
+	free_resolve_handle (handle);
+}
+
+#endif
+
 
 #ifdef HAVE_HOWL
 static gboolean
@@ -1329,7 +1523,25 @@
 	handle->callback_data_destroy_func = callback_data_destroy_func;
 	
 	if (strcmp (domain, "local") == 0) {
-#ifdef HAVE_HOWL
+#ifdef HAVE_AVAHI
+		AvahiClient *client;
+		AvahiServiceResolver *sr;
+
+		handle->is_local = TRUE;
+		client = get_global_avahi_client ();
+		if (client) {
+			sr = avahi_service_resolver_new (client, AVAHI_IF_UNSPEC, AVAHI_PROTO_UNSPEC, 
+							 name, type, domain, AVAHI_PROTO_UNSPEC, 
+							 AVAHI_LOOKUP_USE_MULTICAST,
+							 avahi_resolve_async_callback, handle);
+			if (sr != NULL) {
+				handle->avahi_sr = sr;
+				*handle_out = handle;
+				return GNOME_VFS_OK;
+			}
+		}
+		return GNOME_VFS_ERROR_GENERIC;
+#elif defined (HAVE_HOWL)
 		sw_result res;
 		sw_discovery session;
 		
@@ -1386,6 +1598,10 @@
 gnome_vfs_dns_sd_cancel_resolve (GnomeVFSDNSSDResolveHandle *handle)
 {
 	if (handle->is_local) {
+#ifdef HAVE_AVAHI
+		avahi_service_resolver_free (handle->avahi_sr);
+		free_resolve_handle (handle);
+#endif
 #ifdef HAVE_HOWL
 		g_source_remove (handle->timeout_tag);
 		if (handle->idle_tag) {
@@ -1408,8 +1624,7 @@
 	}
 }
 
-
-#ifdef HAVE_HOWL
+#if defined(HAVE_AVAHI) || defined(HAVE_HOWL)
 static int
 find_existing_service (GArray *array,
 		       const char *name,
@@ -1430,6 +1645,89 @@
 	return -1;
 		    
 }
+#endif
+
+
+#ifdef HAVE_AVAHI
+struct sync_browse_data {
+	AvahiSimplePoll *poll;
+	GArray *array;
+};
+
+static void
+avahi_browse_sync_client_callback (AvahiClient *client, AvahiClientState state, void *user_data)
+{
+	struct sync_browse_data *data;
+
+	data = user_data;
+	if (state == AVAHI_CLIENT_FAILURE) {
+		avahi_simple_poll_quit (data->poll);
+	}
+}
+
+static void 
+avahi_browse_sync_callback (AvahiServiceBrowser *b,
+			    AvahiIfIndex interface,
+			    AvahiProtocol protocol,
+			    AvahiBrowserEvent event,
+			    const char *name,
+			    const char *type,
+			    const char *domain,
+			    AvahiLookupResultFlags flags,
+			    void *user_data)
+{
+	struct sync_browse_data *data;
+	GnomeVFSDNSSDService service, *existing;
+	int i;
+	gboolean free_service;
+
+	data = user_data;
+	
+	free_service = TRUE;
+	service.name = g_strdup (name);
+	service.type = g_strdup (type);
+	service.domain = g_strdup (domain);
+	
+	if (event == AVAHI_BROWSER_NEW) {
+		if (find_existing_service (data->array, service.name, service.type,
+					   service.domain) == -1) {
+			free_service = FALSE;
+			g_array_append_val (data->array, service);
+		} 
+	} else if (event == AVAHI_BROWSER_REMOVE) {
+		i = find_existing_service (data->array, service.name, service.type,
+					   service.domain);
+		if (i != -1) {
+			existing = &g_array_index (data->array, GnomeVFSDNSSDService, i);
+			g_free (existing->name);
+			g_free (existing->type);
+			g_free (existing->domain);
+			g_array_remove_index (data->array, i);
+		}
+	} else if (event == AVAHI_BROWSER_ALL_FOR_NOW) {
+		avahi_simple_poll_quit (data->poll);
+	}
+
+
+	if (free_service) {
+		g_free (service.name);
+		g_free (service.type);
+		g_free (service.domain);
+	}	
+}
+
+static void
+stop_poll_timeout (AvahiTimeout *timeout, void *user_data)
+{
+	AvahiSimplePoll *poll = user_data;
+	
+	avahi_simple_poll_quit (poll);
+}
+
+#endif
+
+
+#ifdef HAVE_HOWL
 
 
 static sw_result
@@ -1530,7 +1828,66 @@
 	*services = NULL;
 	
 	if (strcmp (domain, "local") == 0) {
-#ifdef HAVE_HOWL
+#ifdef HAVE_AVAHI
+		AvahiSimplePoll *simple_poll;
+		const AvahiPoll *poll;
+		AvahiClient *client = NULL;
+		AvahiServiceBrowser *sb;
+		int error;
+		GArray *array;
+		struct sync_browse_data data;
+		struct timeval tv;
+
+		simple_poll = avahi_simple_poll_new ();
+		data.poll = simple_poll;
+		if (simple_poll == NULL) {
+			g_warning ("Failed to create simple poll object");
+			return GNOME_VFS_ERROR_GENERIC;
+		}
+
+		poll = avahi_simple_poll_get (simple_poll);
+		client = avahi_client_new (poll, 0,
+					   avahi_browse_sync_client_callback, &data, &error);
+		
+		/* Check wether creating the client object succeeded */
+		if (client == NULL) {
+			g_warning ("Failed to create client: %s\n", avahi_strerror (error));
+			avahi_simple_poll_free (simple_poll);
+			return GNOME_VFS_ERROR_GENERIC;
+		}
+
+
+		array = g_array_new (FALSE, FALSE, sizeof (GnomeVFSDNSSDService));
+		data.array = array;
+		sb = avahi_service_browser_new (client, AVAHI_IF_UNSPEC, AVAHI_PROTO_UNSPEC, type, NULL, 
+						AVAHI_LOOKUP_USE_MULTICAST, avahi_browse_sync_callback, &data);
+		if (sb == NULL) {
+			g_warning ("Failed to create service browser: %s\n", avahi_strerror (avahi_client_errno (client)));
+			g_array_free (array, TRUE);
+			avahi_client_free (client);
+			avahi_simple_poll_free (simple_poll);
+			return GNOME_VFS_ERROR_GENERIC;
+		}
+
+
+		avahi_elapse_time (&tv, timeout_msec,  0);
+		poll->timeout_new (poll, &tv, stop_poll_timeout, (void *)simple_poll);
+
+		/* Run the main loop util reply or timeout */
+		for (;;)
+			if (avahi_simple_poll_iterate (simple_poll, -1) != 0)
+				break;
+
+		
+		avahi_service_browser_free (sb);
+		avahi_client_free (client);
+		avahi_simple_poll_free (simple_poll);
+
+		*n_services = array->len;
+		*services = (GnomeVFSDNSSDService *)g_array_free (array, FALSE);
+		
+		return GNOME_VFS_OK;
+#elif defined (HAVE_HOWL)
 		sw_discovery session;
 		sw_salt salt;
 		sw_result res;
@@ -1599,6 +1956,63 @@
 	}
 }
 
+#ifdef HAVE_AVAHI
+struct sync_resolve_data {
+	AvahiSimplePoll *poll;
+	gboolean got_data;
+	char *host;
+	int port;
+	char *text;
+	int text_len;
+};
+
+
+static void
+avahi_resolve_sync_client_callback (AvahiClient *c, AvahiClientState state, void *user_data)
+{
+	struct sync_resolve_data *data;
+
+	data = user_data;
+	if (state == AVAHI_CLIENT_FAILURE) {
+		avahi_simple_poll_quit (data->poll);
+	}
+}
+
+static void
+avahi_resolve_sync_callback (AvahiServiceResolver *r,
+			     AvahiIfIndex interface,
+			     AvahiProtocol protocol,
+			     AvahiResolverEvent event,
+			     const char *name,
+			     const char *type,
+			     const char *domain,
+			     const char *host_name,
+			     const AvahiAddress *address,
+			     uint16_t port,
+			     AvahiStringList *txt,
+			     AvahiLookupResultFlags flags,
+			     void *user_data)
+{
+	struct sync_resolve_data *data;
+	char a[128];
+
+	data = user_data;
+	if (event == AVAHI_RESOLVER_FOUND) {
+		data->got_data = TRUE;
+		avahi_address_snprint (a, sizeof(a), address);
+		data->host = g_strdup (a);
+		data->port = port;
+		data->text_len = avahi_string_list_serialize (txt, NULL, 0);
+		data->text = g_malloc (data->text_len);
+		avahi_string_list_serialize (txt, data->text, data->text_len);
+	}
+	
+	avahi_service_resolver_free (r);
+        avahi_simple_poll_quit (data->poll);
+}
+
+#endif
+
 #ifdef HAVE_HOWL
 struct sync_resolve_data {
 	gboolean got_data;
@@ -1672,7 +2086,65 @@
 	GnomeVFSResult res;
 	
 	if (strcmp (domain, "local") == 0) {
-#ifdef HAVE_HOWL
+#ifdef HAVE_AVAHI
+		AvahiSimplePoll *simple_poll;
+		AvahiClient *client = NULL;
+		AvahiServiceResolver *sr;
+		int error;
+		struct sync_resolve_data resolve_data = {0};
+
+		simple_poll = avahi_simple_poll_new ();
+		resolve_data.poll = simple_poll;
+		if (simple_poll == NULL) {
+			g_warning ("Failed to create simple poll object");
+			return GNOME_VFS_ERROR_GENERIC;
+		}
+
+		client = avahi_client_new (avahi_simple_poll_get (simple_poll), 0, 
+					   avahi_resolve_sync_client_callback, &resolve_data, &error);
+		
+		/* Check wether creating the client object succeeded */
+		if (client == NULL) {
+			g_warning ("Failed to create client: %s\n", avahi_strerror (error));
+			avahi_simple_poll_free (simple_poll);
+			return GNOME_VFS_ERROR_GENERIC;
+		}
+		
+		sr = avahi_service_resolver_new (client, AVAHI_IF_UNSPEC, AVAHI_PROTO_UNSPEC, 
+						 name, type, domain, AVAHI_PROTO_UNSPEC, 
+						 AVAHI_LOOKUP_USE_MULTICAST,
+						 avahi_resolve_sync_callback, &resolve_data);
+		if (sr == NULL) {
+			g_warning ("Failed to resolve service '%s': %s\n", name, avahi_strerror (avahi_client_errno (client)));
+			avahi_client_free (client);
+			avahi_simple_poll_free (simple_poll);
+			return GNOME_VFS_ERROR_GENERIC;
+		}
+
+		/* Run the main loop util reply or timeout */
+		for (;;)
+			if (avahi_simple_poll_iterate (simple_poll, -1) != 0)
+				break;
+
+		avahi_client_free (client);
+		avahi_simple_poll_free (simple_poll);
+
+		if (resolve_data.got_data) {
+			*host = resolve_data.host;
+			*port = resolve_data.port;
+			if (text != NULL)
+				*text = decode_txt_record (resolve_data.text, resolve_data.text_len);
+			if (text_raw_len_out != NULL && text_raw_out) {
+				*text_raw_len_out = resolve_data.text_len;
+				*text_raw_out = resolve_data.text;
+			} else {
+				g_free (resolve_data.text);
+			}
+			return GNOME_VFS_OK;
+		}
+		
+		return GNOME_VFS_ERROR_HOST_NOT_FOUND;
+#elif defined (HAVE_HOWL)
 		sw_discovery session;
 		sw_salt salt;
 		sw_result res;
