--- gnome-session/gsm-manager.c.orig	2009-07-28 21:51:22.000000000 -0400
+++ gnome-session/gsm-manager.c	2009-08-26 14:54:08.000000000 -0400
@@ -38,8 +38,6 @@
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
-#include <devkit-power-gobject/devicekit-power.h>
-
 #include <gtk/gtk.h> /* for logout dialog */
 #include <gconf/gconf-client.h>
 
@@ -60,6 +58,7 @@
 #include "gsm-logout-dialog.h"
 #include "gsm-inhibit-dialog.h"
 #include "gsm-consolekit.h"
+#include "gsm-power-manager.h"
 #include "gsm-session-save.h"
 
 #define GSM_MANAGER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GSM_TYPE_MANAGER, GsmManagerPrivate))
@@ -131,9 +130,6 @@ struct GsmManagerPrivate
 
         DBusGProxy             *bus_proxy;
         DBusGConnection        *connection;
-
-        /* Interface with other parts of the system */
-        DkpClient              *dkp_client;
 };
 
 enum {
@@ -927,47 +923,29 @@ manager_switch_user (GsmManager *manager
 static void
 manager_attempt_hibernate (GsmManager *manager)
 {
-        gboolean  can_hibernate;
-        GError   *error;
-        gboolean  ret;
+        GsmPowerManager *power_manager;
 
-        g_object_get (manager->priv->dkp_client,
-                      "can-hibernate", &can_hibernate,
-                      NULL);
-
-        if (can_hibernate) {
-                error = NULL;
-                ret = dkp_client_hibernate (manager->priv->dkp_client, &error);
+        power_manager = gsm_get_power_manager ();
 
-                if (!ret) {
-                        g_warning ("Unexpected hibernate failure: %s",
-                                   error->message);
-                        g_error_free (error);
-                }
+        if (gsm_power_manager_can_hibernate (power_manager)) {
+                gsm_power_manager_attempt_hibernate (power_manager);
         }
+
+        g_object_unref (power_manager);
 }
 
 static void
 manager_attempt_suspend (GsmManager *manager)
 {
-        gboolean  can_suspend;
-        GError   *error;
-        gboolean  ret;
+        GsmPowerManager *power_manager;
 
-        g_object_get (manager->priv->dkp_client,
-                      "can-suspend", &can_suspend,
-                      NULL);
-
-        if (can_suspend) {
-                error = NULL;
-                ret = dkp_client_suspend (manager->priv->dkp_client, &error);
+        power_manager = gsm_get_power_manager ();
 
-                if (!ret) {
-                        g_warning ("Unexpected suspend failure: %s",
-                                   error->message);
-                        g_error_free (error);
-                }
+        if (gsm_power_manager_can_suspend (power_manager)) {
+                gsm_power_manager_attempt_suspend (power_manager);
         }
+
+        g_object_unref (power_manager);
 }
 
 static void
@@ -2140,11 +2118,6 @@ gsm_manager_dispose (GObject *object)
                 manager->priv->gconf_client = NULL;
         }
 
-        if (manager->priv->dkp_client != NULL) {
-                g_object_unref (manager->priv->dkp_client);
-                manager->priv->dkp_client = NULL;
-        }
-
         G_OBJECT_CLASS (gsm_manager_parent_class)->dispose (object);
 }
 
@@ -2373,8 +2346,6 @@ gsm_manager_init (GsmManager *manager)
                           G_CALLBACK (on_presence_status_changed),
                           manager);
 
-        manager->priv->dkp_client = dkp_client_new ();
-
         /* GConf setup */
         gconf_client_add_dir (manager->priv->gconf_client,
                               KEY_DESKTOP_DIR,
@@ -2894,24 +2865,20 @@ gsm_manager_can_shutdown (GsmManager *ma
                           GError    **error)
 {
         GsmConsolekit *consolekit;
-        gboolean can_suspend;
-        gboolean can_hibernate;
-
-        g_object_get (manager->priv->dkp_client,
-                      "can-suspend", &can_suspend,
-                      "can-hibernate", &can_hibernate,
-                      NULL);
+        GsmPowerManager *power_manager;
 
         g_debug ("GsmManager: CanShutdown called");
 
         g_return_val_if_fail (GSM_IS_MANAGER (manager), FALSE);
 
         consolekit = gsm_get_consolekit ();
+        power_manager = gsm_get_power_manager ();
         *shutdown_available = gsm_consolekit_can_stop (consolekit)
                               || gsm_consolekit_can_restart (consolekit)
-                              || can_suspend
-                              || can_hibernate;
+                              || gsm_power_manager_can_suspend (power_manager)
+                              || gsm_power_manager_can_hibernate (power_manager);
         g_object_unref (consolekit);
+        g_object_unref (power_manager);
 
         return TRUE;
 }
