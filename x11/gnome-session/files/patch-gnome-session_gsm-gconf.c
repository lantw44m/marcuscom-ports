--- gnome-session/gsm-gconf.c.orig	2010-02-09 14:22:01.000000000 +0100
+++ gnome-session/gsm-gconf.c	2013-01-24 12:52:40.000000000 +0100
@@ -46,20 +46,23 @@
 gsm_gconf_init (void)
 {
         GError *error = NULL;
-        char   *argv[2];
+        char   *argv[3];
 
         /* Run gconf-sanity-check. As a side effect, this will cause gconfd
          * to be started. (We do this asynchronously so that other GSM
          * initialization can happen in parallel.)
          */
 
+	/* run gconftool-2 --spawn instead of removed gconf-sanity-check. */
+
         argv[0] = GCONF_SANITY_CHECK;
-        argv[1] = NULL;
+        argv[1] = "--spawn";
+        argv[2] = NULL;
 
         g_spawn_async (NULL, argv, NULL, G_SPAWN_DO_NOT_REAP_CHILD,
                        unset_display_setup, NULL, &gsc_pid, &error);
         if (error != NULL) {
-                g_warning ("Failed to run gconf-sanity-check-2: %s\n",
+                g_warning ("Failed to run gconftool-2: %s\n",
                            error->message);
                 g_error_free (error);
 
