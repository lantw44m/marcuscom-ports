--- src/eggdbus/eggdbusmessage.c.orig	2009-08-01 10:53:49.000000000 +0200
+++ src/eggdbus/eggdbusmessage.c	2009-08-01 10:54:19.000000000 +0200
@@ -127,6 +127,7 @@ egg_dbus_message_finalize (GObject *obje
   g_free (priv->signal_name);
   g_free (priv->sender);
   g_free (priv->destination);
+  g_free (priv->object_path);
   g_free (priv->error_name);
   g_free (priv->error_message);
 
