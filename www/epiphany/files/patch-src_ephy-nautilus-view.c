--- src/ephy-nautilus-view.c.orig	Sat Oct 18 00:41:25 2003
+++ src/ephy-nautilus-view.c	Sat Nov 29 14:36:38 2003
@@ -312,8 +312,8 @@
 
 		g_return_val_if_fail (url, FALSE);
 
-		nautilus_view_open_location_force_new_window (NAUTILUS_VIEW (view),
-							      url, NULL);
+		nautilus_view_open_location (NAUTILUS_VIEW (view), url,
+			Nautilus_ViewFrame_OPEN_IN_NAVIGATION, 0, NULL);
 	}
 
 	return FALSE;
@@ -461,8 +461,8 @@
 	
 	ephy_embed_event_get_property (info, "link", &value);
 
-	nautilus_view_open_location_force_new_window (NAUTILUS_VIEW (view),
-						      g_value_get_string (value), NULL);
+	nautilus_view_open_location (NAUTILUS_VIEW (view), g_value_get_string (value),
+		Nautilus_ViewFrame_OPEN_IN_NAVIGATION, 0, NULL);
 }
 
 static void 
@@ -480,8 +480,10 @@
 	
 	ephy_embed_event_get_property (info, "image", &value);
 
-	nautilus_view_open_location_force_new_window (NAUTILUS_VIEW (view),
-						      g_value_get_string (value), NULL);
+	nautilus_view_open_location (NAUTILUS_VIEW (view),
+		g_value_get_string (value),
+		Nautilus_ViewFrame_OPEN_IN_NAVIGATION,
+		0, NULL);
 }
 
 static void 
@@ -499,8 +501,11 @@
 	
 	ephy_embed_get_location (view->priv->embed, FALSE, &location);
 
-	nautilus_view_open_location_force_new_window (NAUTILUS_VIEW (view),
-						      location, NULL);
+	nautilus_view_open_location (NAUTILUS_VIEW (view),
+		location,
+		Nautilus_ViewFrame_OPEN_IN_NAVIGATION,
+		0, NULL);
+
 	g_free (location);
 }
 
