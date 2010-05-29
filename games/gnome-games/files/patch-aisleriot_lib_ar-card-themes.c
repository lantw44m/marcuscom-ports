From a4dd39444218a98fb80c5d9e4a0337a12bc858c2 Mon Sep 17 00:00:00 2001
From: Christian Persch <chpe@gnome.org>
Date: Tue, 25 May 2010 19:14:52 +0000
Subject: aisleriot: Fix for recent GDBus API change

Adapt to the API change, and update gio req to 2.25.7.
---
diff --git a/aisleriot/lib/ar-card-themes.c b/aisleriot/lib/ar-card-themes.c
index e82904f..d3e326a 100644
--- aisleriot/lib/ar-card-themes.c
+++ aisleriot/lib/ar-card-themes.c
@@ -25,7 +25,7 @@
 #include <gdk-pixbuf/gdk-pixbuf.h>
 #include <gtk/gtk.h>
 
-#if GLIB_CHECK_VERSION (2, 25, 5)
+#if GLIB_CHECK_VERSION (2, 25, 7)
 #include <gio/gio.h>
 #endif
 
@@ -368,7 +368,7 @@ themes_foreach_any (gpointer key,
   data->theme = ar_card_themes_get_theme (data->theme_manager, theme_info);
 }
 
-#if GLIB_CHECK_VERSION (2, 25, 5)
+#if GLIB_CHECK_VERSION (2, 25, 7)
 
 static void
 theme_install_reply_cb (GDBusConnection  *connection,
@@ -395,7 +395,7 @@ theme_install_reply_cb (GDBusConnection  *connection,
   g_object_unref (theme_manager);
 }
 
-#endif /* GLIB >= 2.25.5 */
+#endif /* GLIB >= 2.25.7 */
 
 /* Class implementation */
 
@@ -650,7 +650,7 @@ ar_card_themes_get_themes (ArCardThemes *theme_manager)
 gboolean
 ar_card_themes_can_install_themes (ArCardThemes *theme_manager)
 {
-#if GLIB_CHECK_VERSION (2, 25, 5)
+#if GLIB_CHECK_VERSION (2, 25, 7)
   return TRUE;
 #else
   return FALSE;
@@ -670,7 +670,7 @@ ar_card_themes_install_themes (ArCardThemes *theme_manager,
                                   GtkWindow *parent_window,
                                   guint user_time)
 {
-#if GLIB_CHECK_VERSION (2, 25, 5)
+#if GLIB_CHECK_VERSION (2, 25, 7)
   static const char *formats[] = {
 #ifdef ENABLE_CARD_THEME_FORMAT_SVG
     "ThemesSVG",
@@ -753,10 +753,11 @@ ar_card_themes_install_themes (ArCardThemes *theme_manager,
                           "org.freedesktop.PackageKit.Modify",
                           "InstallPackageNames",
                           g_variant_builder_end (&builder),
+                          G_VARIANT_TYPE ("()"),
                           G_DBUS_CALL_FLAGS_NONE,
                           G_MAXINT /* no timeout */,
                           NULL,
                           (GAsyncReadyCallback) theme_install_reply_cb,
                           g_object_ref (theme_manager));
-#endif /* GLIB >= 2.25.5 */
+#endif /* GLIB >= 2.25.7 */
 }
--
cgit v0.8.3.1
