--- blackjack/src/blackjack.cpp.orig	Tue Nov 30 00:38:24 2004
+++ blackjack/src/blackjack.cpp	Tue Nov 30 00:39:26 2004
@@ -655,6 +655,7 @@
         GError             *error      = NULL;
         char               *variation  = NULL;
         gboolean            retval;
+        int rsvg_init ();
         static GOptionEntry entries [] = {
                 { "variation", 0, 0, G_OPTION_ARG_STRING, &variation,
                   N_("Blackjack rule set to use"), NULL },
@@ -674,7 +675,6 @@
 
         gtk_init_with_args (&argc, &argv, NULL, NULL, NULL, &error);
 
-        rsvg_init ();
         gconf_init (argc, argv, NULL);
         gconf_client_add_dir (bj_gconf_client (), GCONF_KEY_DIR,
                               GCONF_CLIENT_PRELOAD_NONE, NULL);
