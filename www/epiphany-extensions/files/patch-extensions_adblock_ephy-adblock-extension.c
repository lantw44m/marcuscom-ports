From 979a0e24a1ebe245004942433d3076746f51d5cc Mon Sep 17 00:00:00 2001
From: Diego Escalante Urrelo <descalante@igalia.com>
Date: Tue, 18 May 2010 21:22:49 +0000
Subject: adblock: disable statusbar use

As per Epiphany's master changes.
---
diff --git a/extensions/adblock/ephy-adblock-extension.c b/extensions/adblock/ephy-adblock-extension.c
index a9cef07..dddc232 100644
--- extensions/adblock/ephy-adblock-extension.c
+++ extensions/adblock/ephy-adblock-extension.c
@@ -231,6 +231,7 @@ static const GtkActionEntry edit_entries[] = {
 	  G_CALLBACK (ephy_adblock_extension_edit_cb) }
 };
 
+#if 0
 static gboolean
 ephy_adblock_statusbar_icon_clicked_cb (GtkWidget *widget,
 				        GdkEventButton *event,
@@ -355,6 +356,7 @@ destroy_statusbar_icon (EphyWindow *window)
 
 	ephy_statusbar_remove_widget (statusbar, evbox);
 }
+#endif
 
 static void
 ephy_adblock_extension_edit_cb (GtkAction *action, EphyWindow *window)
@@ -393,8 +395,9 @@ switch_page_cb (GtkNotebook *notebook,
 	/* FIXME: this shouldn't happen anymore with gtk 2.10 ! Test & remove */
 	if (gtk_widget_get_realized (GTK_WIDGET (window)) == FALSE)
 		return; /* on startup */
-
+#if 0
 	update_statusbar (window);
+#endif
 }
 
 static void
@@ -441,7 +444,9 @@ impl_attach_window (EphyExtension *ext,
 	g_object_set_data (G_OBJECT (window), EXTENSION_KEY, ext);
 
 	/* The ad blocked icon */
+#if 0
 	create_statusbar_icon (window);
+#endif
 
 	notebook = ephy_window_get_notebook (window);
 
@@ -474,7 +479,9 @@ impl_detach_window (EphyExtension *ext,
 	g_signal_handlers_disconnect_by_func
 		(notebook, G_CALLBACK (switch_page_cb), window);
 
+#if 0
 	destroy_statusbar_icon (window);
+#endif
 }
 
 static void
@@ -509,7 +516,9 @@ num_blocked_cb (AdBlocker *blocker,
 
 	if (embed == ephy_embed_container_get_active_child (EPHY_EMBED_CONTAINER (window)))
 	{
+#if 0
 		update_statusbar (window);
+#endif
 	}
 }
 
--
cgit v0.8.3.1
