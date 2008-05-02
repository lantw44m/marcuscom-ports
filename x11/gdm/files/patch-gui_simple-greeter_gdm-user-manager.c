--- gui/simple-greeter/gdm-user-manager.c.orig	2008-05-02 14:45:56.000000000 -0400
+++ gui/simple-greeter/gdm-user-manager.c	2008-05-02 14:45:36.000000000 -0400
@@ -1269,17 +1269,21 @@ reload_passwd (GdmUserManager *manager)
         GSList        *old_users;
         GSList        *new_users;
         GSList        *list;
+#ifndef __FreeBSD__
         FILE          *fp;
+#endif
 
         old_users = NULL;
         new_users = NULL;
 
+#ifndef __FreeBSD__
         errno = 0;
         fp = fopen (PATH_PASSWD, "r");
         if (fp == NULL) {
                 g_warning ("Unable to open %s: %s", PATH_PASSWD, g_strerror (errno));
                 goto out;
         }
+#endif
 
         g_hash_table_foreach (manager->priv->users, listify_hash_values_hfunc, &old_users);
         g_slist_foreach (old_users, (GFunc) g_object_ref, NULL);
@@ -1291,7 +1295,13 @@ reload_passwd (GdmUserManager *manager)
                         new_users = g_slist_prepend (new_users, g_object_ref (list->data));
                 }
         }
+#ifdef __FreeBSD__
+	setpwent ();
+
+	for (pwent = getpwent (); pwent != NULL; pwent = getpwent ()) {
+#else
         for (pwent = fgetpwent (fp); pwent != NULL; pwent = fgetpwent (fp)) {
+#endif
                 GdmUser *user;
 
                 user = NULL;
@@ -1354,7 +1364,11 @@ reload_passwd (GdmUserManager *manager)
  out:
         /* Cleanup */
 
+#ifdef __FreeBSD__
+	endpwent ();
+#else
         fclose (fp);
+#endif
 
         g_slist_foreach (new_users, (GFunc) g_object_thaw_notify, NULL);
         g_slist_foreach (new_users, (GFunc) g_object_unref, NULL);
