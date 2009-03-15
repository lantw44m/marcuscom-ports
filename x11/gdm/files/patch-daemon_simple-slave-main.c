--- daemon/simple-slave-main.c	2008/08/15 17:13:36	6382
+++ daemon/simple-slave-main.c	2009/03/14 01:06:00	6769
@@ -43,10 +43,13 @@
 #include "gdm-log.h"
 #include "gdm-common.h"
 #include "gdm-simple-slave.h"
+#include "gdm-settings.h"
+#include "gdm-settings-direct.h"
 
 #include "gdm-settings-client.h"
 
-static int gdm_return_code = 0;
+static GdmSettings     *settings        = NULL;
+static int              gdm_return_code = 0;
 
 static DBusGConnection *
 get_system_bus (void)
@@ -202,6 +205,17 @@
 
         gdm_log_init ();
 
+        settings = gdm_settings_new ();
+        if (settings == NULL) {
+                g_warning ("Unable to initialize settings");
+                goto out;
+        }
+
+        if (! gdm_settings_direct_init (settings, GDMCONFDIR "/gdm.schemas", "/")) {
+                g_warning ("Unable to initialize settings");
+                goto out;
+        }
+
         gdm_log_set_debug (is_debug_set (debug));
 
         if (display_id == NULL) {
