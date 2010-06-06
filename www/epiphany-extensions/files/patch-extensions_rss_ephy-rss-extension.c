From 18127fcbb9010d79d5fbe765685af9fcfcf5ff1b Mon Sep 17 00:00:00 2001
From: Diego Escalante Urrelo <descalante@igalia.com>
Date: Tue, 18 May 2010 21:22:33 +0000
Subject: rss: disable statusbar use

As per Epiphany's master changes.
---
diff --git a/extensions/rss/ephy-rss-extension.c b/extensions/rss/ephy-rss-extension.c
index 2a42fa6..f799b66 100644
--- extensions/rss/ephy-rss-extension.c
+++ extensions/rss/ephy-rss-extension.c
@@ -57,8 +57,10 @@ static GType type = 0;
 
 static void ephy_rss_display_cb 	(GtkAction *action,
 					 EphyWindow *window);
+#if 0
 static void ephy_rss_update_statusbar 	(EphyWindow *window,
 					 gboolean show);
+#endif
 static void ephy_rss_update_action 	(EphyWindow *window);
 static void ephy_rss_feed_subscribe_cb (GtkAction *action,
 					 EphyWindow *window);
@@ -251,6 +253,7 @@ ephy_rss_ge_content_cb (EphyEmbed *embed,
 	ephy_rss_update_action (window);
 }
 
+#if 0
 static void
 ephy_rss_update_statusbar (EphyWindow *window,
 			   gboolean show)
@@ -263,6 +266,7 @@ ephy_rss_update_statusbar (EphyWindow *window,
 
 	g_object_set (data->evbox, "visible", show, NULL);
 }
+#endif
 
 /* Update the menu item availability */
 static void
@@ -289,7 +293,9 @@ ephy_rss_update_action (EphyWindow *window)
 
 	g_object_set (data->info_action, "sensitive", show, NULL);
 
+#if 0
 	ephy_rss_update_statusbar (window, show);
+#endif
 
 	g_object_set (data->subscribe_action,
 		      "sensitive", show,
@@ -360,6 +366,7 @@ impl_detach_tab (EphyExtension *extension,
 	g_object_set_data (G_OBJECT (embed), FEEDLIST_DATA_KEY, NULL);
 }
 
+#if 0
 static gboolean
 ephy_rss_statusbar_icon_clicked_cb (GtkWidget *widget,
 				    GdkEventButton *event,
@@ -414,6 +421,7 @@ ephy_rss_destroy_statusbar_icon (EphyWindow *window,
 
 	ephy_statusbar_remove_widget (statusbar, GTK_WIDGET (data->evbox));
 }
+#endif
 
 /* Create the menu item to subscribe to an rss feed */
 static void
@@ -468,8 +476,10 @@ impl_attach_window (EphyExtension *ext,
 
 	g_object_set_data (G_OBJECT (window), EPHY_RSS_EXTENSION_DATA_KEY, extension);
 
+#if 0
 	/* Create the status bar icon */
 	ephy_rss_create_statusbar_icon (window, data);
+#endif
 
 	/* Register for tab switch events */
 	ephy_rss_sync_active_tab (window, NULL, NULL);
@@ -498,8 +508,10 @@ impl_detach_window (EphyExtension *ext,
 	g_signal_handlers_disconnect_by_func
 		(window, G_CALLBACK (ephy_rss_sync_active_tab), NULL);
 
+#if 0
 	/* Remove the status bar icon */
 	ephy_rss_destroy_statusbar_icon (window, data);
+#endif
 
 	/* Destroy data */
 	g_object_set_data (G_OBJECT (window), WINDOW_DATA_KEY, NULL);
--
cgit v0.8.3.1
