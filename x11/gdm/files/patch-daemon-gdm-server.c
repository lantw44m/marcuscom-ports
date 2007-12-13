--- daemon/gdm-server.c.orig	2007-11-09 10:40:03.000000000 -0500
+++ daemon/gdm-server.c	2007-12-13 12:35:56.000000000 -0500
@@ -32,6 +32,7 @@
 #include <pwd.h>
 #include <grp.h>
 #include <signal.h>
+#include <sys/resource.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -43,6 +44,10 @@
 #include "gdm-common.h"
 #include "gdm-signal-handler.h"
 
+#include "gdm-settings.h"
+#include "gdm-settings-direct.h"
+#include "gdm-settings-keys.h"
+
 #include "gdm-server.h"
 
 extern char **environ;
@@ -76,6 +81,7 @@ struct GdmServerPrivate
         char    *parent_display_name;
         char    *parent_auth_file;
         char    *chosen_hostname;
+	char    *vt;
 
         guint    child_watch_id;
 };
@@ -662,7 +668,7 @@ gdm_server_start (GdmServer *server)
         gboolean res;
 
         /* fork X server process */
-        res = gdm_server_spawn (server, NULL);
+        res = gdm_server_spawn (server, server->priv->vt);
 
         return res;
 }
@@ -889,12 +895,32 @@ static void
 gdm_server_init (GdmServer *server)
 {
 
+	int vt;
+	gboolean has_vt;
+	GdmSettings *settings = NULL;
         server->priv = GDM_SERVER_GET_PRIVATE (server);
 
+	settings = gdm_settings_new ();
+	if (settings == NULL) {
+		g_assert ("Unable to initialize settings");
+	}
+
+	if (! gdm_settings_direct_init (settings, GDMCONFDIR "/gdm.schemas", "/")) {
+		g_assert ("Unable to initialize settings");
+	}
+
+	has_vt = gdm_settings_direct_get_int (GDM_KEY_VT, &vt);
+
+	g_object_unref (settings);
+
         server->priv->pid = -1;
         server->priv->command = g_strdup (X_SERVER " -br -verbose");
         server->priv->log_dir = g_strdup (LOGDIR);
 
+	if (has_vt) {
+		server->priv->vt = g_strdup_printf ("vt %d", vt);
+	}
+
         add_ready_handler (server);
 }
 
