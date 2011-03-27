--- src/daemon.c.orig	2011-03-27 20:15:46.000000000 +0200
+++ src/daemon.c	2011-03-27 20:25:07.000000000 +0200
@@ -50,6 +50,9 @@
 #define PATH_SHADOW "/etc/shadow"
 #define PATH_LOGIN_DEFS "/etc/login.defs"
 
+#ifdef __FreeBSD__
+#define FALLBACK_MINIMAL_UID 1000
+#endif
 #ifndef FALLBACK_MINIMAL_UID
 #define FALLBACK_MINIMAL_UID 500
 #endif
@@ -482,16 +485,24 @@ reload_passwd (Daemon *daemon)
         old_users = NULL;
         new_users = NULL;
 
+#ifdef __FreeBSD__
+       setpwent();
+#else
         errno = 0;
         fp = fopen (PATH_PASSWD, "r");
         if (fp == NULL) {
                 g_warning ("Unable to open %s: %s", PATH_PASSWD, g_strerror (errno));
                 goto out;
         }
+#endif
         g_hash_table_foreach (daemon->priv->users, listify_hash_values_hfunc, &old_users);
         g_slist_foreach (old_users, (GFunc) g_object_ref, NULL);
 
+#ifdef __FreeBSD__
+        for (pwent = getpwent (); pwent != NULL; pwent = getpwent ()) {
+#else
         for (pwent = fgetpwent (fp); pwent != NULL; pwent = fgetpwent (fp)) {
+#endif
                 /* Skip users below MINIMAL_UID... */
                 if (user_is_excluded (daemon, pwent->pw_name, pwent->pw_uid)) {
                         g_debug ("skipping user: %s", pwent->pw_name);
@@ -544,7 +555,11 @@ reload_passwd (Daemon *daemon)
  out:
         /* Cleanup */
 
+#ifdef __FreeBSD__
+        endpwent ();
+#else
         fclose (fp);
+#endif
 
         g_slist_foreach (new_users, (GFunc) g_object_thaw_notify, NULL);
         g_slist_foreach (new_users, (GFunc) g_object_unref, NULL);
@@ -664,6 +679,13 @@ on_passwd_monitor_changed (GFileMonitor 
         reload_users (daemon);
 }
 
+#ifdef __FreeBSD__
+static uid_t
+get_minimal_uid (void)
+{
+	return FALLBACK_MINIMAL_UID;
+}
+#else
 static uid_t
 get_minimal_uid (void)
 {
@@ -716,6 +738,7 @@ out:
         g_free (contents);
         return uid;
 }
+#endif
 
 static void
 daemon_init (Daemon *daemon)
