--- src/daemon.c.orig	2011-08-16 14:53:31.000000000 +0200
+++ src/daemon.c	2011-10-05 00:17:22.000000000 +0200
@@ -52,6 +52,9 @@
 #define PATH_LOGIN_DEFS "/etc/login.defs"
 #define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
 
+#ifdef __FreeBSD__
+#define FALLBACK_MINIMAL_UID 1000
+#endif
 #ifndef FALLBACK_MINIMAL_UID
 #define FALLBACK_MINIMAL_UID 500
 #endif
@@ -243,7 +246,9 @@ reload_wtmp_history (Daemon *daemon)
         GHashTableIter iter;
         gpointer key, value;
 
+#ifdef __linux__
         utmpxname(_PATH_WTMPX);
+#endif
         setutxent ();
 
         login_frequency_hash = g_hash_table_new_full (g_str_hash, g_str_equal, NULL, NULL);
@@ -326,22 +331,32 @@ reload_passwd (Daemon *daemon)
         GSList *old_users;
         GSList *new_users;
         GSList *list;
+#ifndef __FreeBSD__
         FILE *fp;
+#endif
         User *user = NULL;
 
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
                 if (daemon_local_user_is_excluded (daemon, pwent->pw_name, pwent->pw_uid)) {
                         g_debug ("skipping user: %s", pwent->pw_name);
@@ -391,10 +406,13 @@ reload_passwd (Daemon *daemon)
                 }
         }
 
- out:
         /* Cleanup */
-
-        fclose (fp);
+#ifdef __FreeBSD__
+        endpwent ();
+#else
+ out:
+         fclose (fp);
+#endif
 
         g_slist_foreach (new_users, (GFunc) g_object_thaw_notify, NULL);
         g_slist_foreach (new_users, (GFunc) g_object_unref, NULL);
@@ -427,8 +445,8 @@ reload_data (Daemon *daemon)
 static void
 reload_users (Daemon *daemon)
 {
-        reload_wtmp_history (daemon);
         reload_passwd (daemon);
+        reload_wtmp_history (daemon);
         reload_data (daemon);
 }
 
@@ -554,6 +572,13 @@ on_gdm_monitor_changed (GFileMonitor    
         queue_reload_autologin (daemon);
 }
 
+#ifdef __FreeBSD__
+static uid_t
+get_minimal_uid (void)
+{        
+       return FALLBACK_MINIMAL_UID;
+}
+#else
 static uid_t
 get_minimal_uid (void)
 {
@@ -606,6 +631,7 @@ out:
         g_free (contents);
         return uid;
 }
+#endif
 
 static void
 daemon_init (Daemon *daemon)
