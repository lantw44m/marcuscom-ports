--- metadata/rb-metadata-dbus-service.c.orig	Sat Oct  7 21:25:45 2006
+++ metadata/rb-metadata-dbus-service.c	Sat Oct  7 21:25:56 2006
@@ -494,7 +494,7 @@ main (int argc, char **argv)
 	g_main_loop_run (svc.loop);
 
 	if (svc.connection) {
-		dbus_connection_disconnect (svc.connection);
+		dbus_connection_close (svc.connection);
 		dbus_connection_unref (svc.connection);
 	}
 
