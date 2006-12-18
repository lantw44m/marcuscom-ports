--- src/interface.cpp.orig	Sun Dec 17 21:19:35 2006
+++ src/interface.cpp	Sun Dec 17 21:21:53 2006
@@ -654,9 +654,9 @@ disconnect_proxy_cb (GtkUIManager *manag
 {
 	if (GTK_IS_MENU_ITEM (proxy)) {
 		g_signal_handlers_disconnect_by_func
-			(proxy, reinterpret_cast<void*>(G_CALLBACK(menu_item_select_cb)), procdata);
+			(proxy, (void *) (G_CALLBACK(menu_item_select_cb)), procdata);
 		g_signal_handlers_disconnect_by_func
-			(proxy, reinterpret_cast<void*>(G_CALLBACK(menu_item_deselect_cb)), procdata);
+			(proxy, (void *) (G_CALLBACK(menu_item_deselect_cb)), procdata);
 	}
 }
 
