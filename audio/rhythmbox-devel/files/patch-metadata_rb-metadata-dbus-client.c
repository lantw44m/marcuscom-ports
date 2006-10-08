--- metadata/rb-metadata-dbus-client.c.orig	Sat Oct  7 22:33:37 2006
+++ metadata/rb-metadata-dbus-client.c	Sat Oct  7 22:33:48 2006
@@ -118,7 +118,7 @@ kill_metadata_service (void)
 	if (dbus_connection) {
 		if (dbus_connection_get_is_connected (dbus_connection)) {
 			rb_debug ("closing dbus connection");
-			dbus_connection_disconnect (dbus_connection);
+			dbus_connection_close (dbus_connection);
 		} else {
 			rb_debug ("dbus connection already closed");
 		}
