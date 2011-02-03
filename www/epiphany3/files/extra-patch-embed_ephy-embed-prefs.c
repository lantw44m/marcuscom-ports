--- embed/ephy-embed-prefs.c.orig	2010-12-09 09:22:56.000000000 +0000
+++ embed/ephy-embed-prefs.c	2011-01-16 14:51:37.000000000 +0000
@@ -483,6 +483,7 @@ ephy_embed_prefs_init (void)
   /* Hardcoded settings */
   g_object_set (webkit_settings,
                 "auto-shrink-images", FALSE,
+                "enable-spell-checking", TRUE,
                 "enable-default-context-menu", FALSE,
                 "enable-site-specific-quirks", TRUE,
                 "enable-page-cache", TRUE,
