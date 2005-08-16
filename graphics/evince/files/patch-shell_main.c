--- shell/main.c.orig	Tue Aug 16 13:51:21 2005
+++ shell/main.c	Tue Aug 16 13:52:17 2005
@@ -75,9 +75,6 @@ load_files_remote (const char **files)
 	GError *error = NULL;
 	DBusGConnection *connection;
 	gboolean result = FALSE;
-#if DBUS_VERSION < 35
-	DBusGPendingCall *call;
-#endif
 	DBusGProxy *remote_object;
 
 	connection = dbus_g_bus_get (DBUS_BUS_SESSION, &error);
@@ -93,29 +90,11 @@ load_files_remote (const char **files)
                                                    "/org/gnome/evince/Evince",
                                                    "org.gnome.evince.Application");
 	if (!files) {
-#if DBUS_VERSION <= 33
-		call = dbus_g_proxy_begin_call (remote_object, "OpenWindow", DBUS_TYPE_INVALID);
-
-		if (!dbus_g_proxy_end_call (remote_object, call, &error, DBUS_TYPE_INVALID)) {
-			g_warning (error->message);
-			g_clear_error (&error);
-			return FALSE;
-		}
-#elif DBUS_VERSION == 34
-		call = dbus_g_proxy_begin_call (remote_object, "OpenWindow", G_TYPE_INVALID);
-
-		if (!dbus_g_proxy_end_call (remote_object, call, &error, G_TYPE_INVALID)) {
-			g_warning (error->message);
-			g_clear_error (&error);
-			return FALSE;
-		}
-#else
 		if (!dbus_g_proxy_call (remote_object, "OpenWindow", &error, G_TYPE_INVALID)) {
 			g_warning (error->message);
 			g_clear_error (&error);
 			return FALSE;
 		}
-#endif
 		return TRUE;
 	}
 
@@ -125,31 +104,6 @@ load_files_remote (const char **files)
 
 		uri = gnome_vfs_make_uri_from_shell_arg (files[i]);
 		page_label = ev_page_label ? ev_page_label : ""; 
-#if DBUS_VERSION <= 33
-		call = dbus_g_proxy_begin_call (remote_object, "OpenURI",
-						DBUS_TYPE_STRING, &uri,
-						DBUS_TYPE_STRING, &page_label,
-						DBUS_TYPE_INVALID);
-
-		if (!dbus_g_proxy_end_call (remote_object, call, &error, DBUS_TYPE_INVALID)) {
-			g_warning (error->message);
-			g_clear_error (&error);
-			g_free (uri);
-			continue;
-		}
-#elif DBUS_VERSION == 34
-		call = dbus_g_proxy_begin_call (remote_object, "OpenURI",
-						G_TYPE_STRING, uri,
-						G_TYPE_STRING, page_label,
-						G_TYPE_INVALID);
-
-		if (!dbus_g_proxy_end_call (remote_object, call, &error, G_TYPE_INVALID)) {
-			g_warning (error->message);
-			g_clear_error (&error);
-			g_free (uri);
-			continue;
-		}
-#else
 		if (!dbus_g_proxy_call (remote_object, "OpenURI", &error,
 					G_TYPE_STRING, uri,
 					G_TYPE_STRING, page_label,
@@ -159,7 +113,6 @@ load_files_remote (const char **files)
 			g_free (uri);
 			continue;
 		}
-#endif
 		g_free (uri);
 		result = TRUE;
         }
