--- shell/ev-application.c.orig	Tue Aug 16 13:36:09 2005
+++ shell/ev-application.c	Tue Aug 16 13:50:19 2005
@@ -83,13 +83,8 @@ ev_application_register_service (EvAppli
 		return FALSE;
 	}
 
-#if DBUS_VERSION == 33
-	dbus_g_object_class_install_info (G_OBJECT_GET_CLASS (application),
-					  &dbus_glib_ev_application_object_info);
-#else
 	dbus_g_object_type_install_info (EV_TYPE_APPLICATION,
 					 &dbus_glib_ev_application_object_info);
-#endif
 
 	dbus_g_connection_register_g_object (connection,
 					     "/org/gnome/evince/Evince",
