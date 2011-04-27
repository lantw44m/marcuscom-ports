--- embed/ephy-embed-prefs.c.orig	2011-04-27 17:46:35.000000000 +0200
+++ embed/ephy-embed-prefs.c	2011-04-27 17:47:14.000000000 +0200
@@ -481,8 +483,8 @@ ephy_embed_prefs_init (void)
 
   /* Hardcoded settings */
   g_object_set (webkit_settings,
-                "enable-default-context-menu", FALSE,
                 "enable-spell-checking", TRUE,
+                "enable-default-context-menu", FALSE,
                 "enable-site-specific-quirks", TRUE,
                 "enable-page-cache", TRUE,
                 "enable-developer-extras", TRUE,
