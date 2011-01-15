--- src/gdmuser/gdm-user-manager.c.orig	2010-12-08 21:06:50.000000000 +0000
+++ src/gdmuser/gdm-user-manager.c	2011-01-15 18:39:35.000000000 +0000
@@ -2230,9 +2230,9 @@ reload_passwd_file (GHashTable *valid_sh
 
                 g_debug ("GdmUserManager: include_all is TRUE");
 
-                for (pwent = fgetpwent (fp);
+                for (pwent = getpwent ();
                      pwent != NULL;
-                     pwent = fgetpwent (fp)) {
+                     pwent = getpwent ()) {
 
                         /* Skip users below MinimalUID... */
                         if (pwent->pw_uid < FALLBACK_MINIMAL_UID) {
