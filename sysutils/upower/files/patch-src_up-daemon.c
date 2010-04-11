--- src/up-daemon.c.orig	2010-04-11 19:51:10.000000000 -0400
+++ src/up-daemon.c	2010-04-11 19:51:33.000000000 -0400
@@ -480,6 +480,8 @@ up_daemon_suspend_allowed (UpDaemon *dae
 		goto out;
 
 	ret = up_polkit_is_allowed (daemon->priv->polkit, subject, "org.freedesktop.upower.suspend", context);
+	if (!ret)
+		goto out;
 	dbus_g_method_return (context, ret);
 
 out:
@@ -564,6 +566,8 @@ up_daemon_hibernate_allowed (UpDaemon *d
 		goto out;
 
 	ret = up_polkit_is_allowed (daemon->priv->polkit, subject, "org.freedesktop.upower.hibernate", context);
+	if (!ret)
+		goto out;
 	dbus_g_method_return (context, ret);
 
 out:
