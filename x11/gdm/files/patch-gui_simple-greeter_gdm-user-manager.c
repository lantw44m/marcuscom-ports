--- gui/simple-greeter/gdm-user-manager.c.orig	2010-07-12 23:17:16.000000000 +0200
+++ gui/simple-greeter/gdm-user-manager.c	2010-07-26 18:19:57.000000000 +0200
@@ -60,6 +60,8 @@
 
 #ifdef __sun
 #define FALLBACK_MINIMAL_UID     100
+#elif defined(__FreeBSD__)
+#define FALLBACK_MINIMAL_UID     1000
 #else
 #define FALLBACK_MINIMAL_UID     500
 #endif
@@ -1548,12 +1550,17 @@ reload_passwd_file (GHashTable *valid_sh
                                                    NULL,
                                                    g_object_unref);
 
+#ifdef __FreeBSD__
+	setpwent ();
+#else
+
         errno = 0;
         fp = fopen (PATH_PASSWD, "r");
         if (fp == NULL) {
                 g_warning ("Unable to open %s: %s", PATH_PASSWD, g_strerror (errno));
                 goto out;
         }
+#endif
 
         /* Make sure we keep users who are logged in no matter what. */
         g_hash_table_iter_init (&iter, current_users_by_name);
@@ -1603,9 +1610,15 @@ reload_passwd_file (GHashTable *valid_sh
 
                 g_debug ("GdmUserManager: include_all is TRUE");
 
+#ifdef __FreeBSD__
+		for (pwent = getpwent ();
+		     pwent != NULL;
+		     pwent = getpwent ()) {
+#else
                 for (pwent = fgetpwent (fp);
                      pwent != NULL;
                      pwent = fgetpwent (fp)) {
+#endif
 
                         /* Skip users below MinimalUID... */
                         if (pwent->pw_uid < FALLBACK_MINIMAL_UID) {
@@ -1680,7 +1693,11 @@ reload_passwd_file (GHashTable *valid_sh
  out:
         /* Cleanup */
 
+#ifdef __FreeBSD__
+	endpwent ();
+#else
         fclose (fp);
+#endif
 
         g_hash_table_iter_init (&iter, new_users_by_name);
         while (g_hash_table_iter_next (&iter, (gpointer *) &name, (gpointer *) &user)) {
