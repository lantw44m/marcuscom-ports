--- gui/simple-greeter/gdm-user-manager.c.orig	2009-07-20 03:09:09.000000000 +0200
+++ gui/simple-greeter/gdm-user-manager.c	2009-07-20 10:07:37.000000000 +0200
@@ -1303,17 +1303,24 @@ reload_passwd (GdmUserManager *manager)
         GSList        *new_users;
         GSList        *list;
         GSList        *dup;
+#ifndef __FreeBSD__
         FILE          *fp;
+#endif
 
         old_users = NULL;
         new_users = NULL;
 
+#ifdef __FreeBSD__
+        setpwent ();
+#else
+
         errno = 0;
         fp = fopen (PATH_PASSWD, "r");
         if (fp == NULL) {
                 g_warning ("Unable to open %s: %s", PATH_PASSWD, g_strerror (errno));
                 goto out;
         }
+#endif
 
         g_hash_table_foreach (manager->priv->users, listify_hash_values_hfunc, &old_users);
         g_slist_foreach (old_users, (GFunc) g_object_ref, NULL);
@@ -1327,7 +1334,11 @@ reload_passwd (GdmUserManager *manager)
                 }
         }
 
+#ifdef __FreeBSD__
+        for (pwent = getpwent (); pwent != NULL; pwent = getpwent ()) {
+#else
         for (pwent = fgetpwent (fp); pwent != NULL; pwent = fgetpwent (fp)) {
+#endif
                 GdmUser *user;
 
                 user = NULL;
@@ -1398,7 +1409,11 @@ reload_passwd (GdmUserManager *manager)
  out:
         /* Cleanup */
 
+#ifdef __FreeBSD__
+	endpwent ();
+#else
         fclose (fp);
+#endif
 
         g_slist_foreach (new_users, (GFunc) g_object_thaw_notify, NULL);
         g_slist_foreach (new_users, (GFunc) g_object_unref, NULL);
