--- registryd/deviceeventcontroller.c.orig	2012-06-29 10:32:08.000000000 +0200
+++ registryd/deviceeventcontroller.c	2012-06-29 10:33:19.000000000 +0200
@@ -1225,11 +1225,11 @@
                                                 "org.freedesktop.DBus.Peer",
                                                 "Ping");
         if (!message)
-          return;
+          return NULL;
         dbus_connection_send_with_reply (bus, message, &pending, -1);
         dbus_message_unref (message);
         if (!pending)
-          return;
+          return NULL;
         bus_name_dup = g_strdup (dest);
         dbus_pending_call_set_notify (pending, reset_hung_process_from_ping,
                                       bus_name_dup, NULL);
