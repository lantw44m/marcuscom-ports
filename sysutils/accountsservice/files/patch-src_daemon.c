--- src/daemon.c.orig	2012-06-28 17:24:55.000000000 +0200
+++ src/daemon.c	2012-06-29 10:44:09.000000000 +0200
@@ -49,7 +49,7 @@
 #define PATH_SHADOW "/etc/shadow"
 #define PATH_NOLOGIN "/sbin/nologin"
 #define PATH_FALSE "/bin/false"
-#define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
+#define PATH_GDM_CUSTOM "/usr/local/etc/gdm/custom.conf"
 
 static const char *default_excludes[] = {
         "bin",
@@ -68,6 +68,7 @@
         "nobody4",
         "noaccess",
         "postgres",
+        "pgsql",
         "pvm",
         "rpm",
         "nfsnobody",
@@ -77,6 +78,7 @@
         "games",
         "man",
         "at",
+        "saned",
         NULL
 };
 
@@ -315,7 +317,13 @@
         g_hash_table_foreach (daemon->priv->users, listify_hash_values_hfunc, &old_users);
         g_slist_foreach (old_users, (GFunc) g_object_ref, NULL);
 
+#ifdef HAVE_FGETPWENT
         while ((pwent = fgetpwent (fp)) != NULL) {
+#else
+        setpwent();
+
+        while ((pwent = getpwent ()) != NULL) {
+#endif
                 /* Skip system users... */
                 if (daemon_local_user_is_excluded (daemon, pwent->pw_name, pwent->pw_shell)) {
                         g_debug ("skipping user: %s", pwent->pw_name);
