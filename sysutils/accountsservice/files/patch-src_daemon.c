--- src/daemon.c.orig	2011-10-16 20:25:13.000000000 +0200
+++ src/daemon.c	2011-10-16 20:28:05.000000000 +0200
@@ -32,7 +32,9 @@
 #include <errno.h>
 #include <unistd.h>
 #include <sys/types.h>
+#ifdef HAVE_UTMPX_H
 #include <utmpx.h>
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -52,6 +54,9 @@
 #define PATH_LOGIN_DEFS "/etc/login.defs"
 #define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
 
+#ifdef __FreeBSD__
+#define FALLBACK_MINIMAL_UID 1000
+#endif
 #ifndef FALLBACK_MINIMAL_UID
 #define FALLBACK_MINIMAL_UID 500
 #endif
@@ -238,13 +243,19 @@ daemon_local_user_is_excluded (Daemon *d
 static void
 reload_wtmp_history (Daemon *daemon)
 {
+#ifdef HAVE_UTMPX_H
         struct utmpx *wtmp_entry;
         GHashTable *login_frequency_hash;
         GHashTableIter iter;
         gpointer key, value;
 
-        utmpxname(_PATH_WTMPX);
+#ifdef UTXDB_LOG
+        if (setutxdb (UTXDB_LOG, NULL) != 0)
+                return;
+#else
+        utmpxname (_PATH_WTMPX);
         setutxent ();
+#endif
 
         login_frequency_hash = g_hash_table_new_full (g_str_hash, g_str_equal, NULL, NULL);
 
@@ -298,6 +309,7 @@ reload_wtmp_history (Daemon *daemon)
 
         g_hash_table_foreach (login_frequency_hash, (GHFunc) g_free, NULL);
         g_hash_table_unref (login_frequency_hash);
+#endif /* HAVE_UTMPX_H */
 }
 
 static void
@@ -326,22 +338,32 @@ reload_passwd (Daemon *daemon)
         GSList *old_users;
         GSList *new_users;
         GSList *list;
+#ifdef HAVE_FGETPWENT
         FILE *fp;
+#endif
         User *user = NULL;
 
         old_users = NULL;
         new_users = NULL;
 
+#ifdef HAVE_FGETPWENT
         errno = 0;
         fp = fopen (PATH_PASSWD, "r");
         if (fp == NULL) {
                 g_warning ("Unable to open %s: %s", PATH_PASSWD, g_strerror (errno));
                 goto out;
         }
+#else
+        setpwent();
+#endif
         g_hash_table_foreach (daemon->priv->users, listify_hash_values_hfunc, &old_users);
         g_slist_foreach (old_users, (GFunc) g_object_ref, NULL);
 
-        for (pwent = fgetpwent (fp); pwent != NULL; pwent = fgetpwent (fp)) {
+#ifdef HAVE_FGETPWENT
+        while ((pwent = fgetpwent (fp)) != NULL) {
+#else
+        while ((pwent = getpwent ()) != NULL) {
+#endif
                 /* Skip users below MINIMAL_UID... */
                 if (daemon_local_user_is_excluded (daemon, pwent->pw_name, pwent->pw_uid)) {
                         g_debug ("skipping user: %s", pwent->pw_name);
@@ -391,10 +413,12 @@ reload_passwd (Daemon *daemon)
                 }
         }
 
+#ifdef HAVE_FGETPWENT
  out:
         /* Cleanup */
 
         fclose (fp);
+#endif
 
         g_slist_foreach (new_users, (GFunc) g_object_thaw_notify, NULL);
         g_slist_foreach (new_users, (GFunc) g_object_unref, NULL);
