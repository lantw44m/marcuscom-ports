--- stickynotes/stickynotes_applet.c.orig	Sun Feb 22 19:32:18 2004
+++ stickynotes/stickynotes_applet.c	Sun Feb 22 19:34:42 2004
@@ -337,20 +337,24 @@
 
 void stickynotes_applet_update_prefs()
 {
-	gint width = gconf_client_get_int(stickynotes->gconf, GCONF_PATH "/defaults/width", NULL);
+    	gint width, height;
+	gboolean sys_color, sys_font, click_behavior, sticky, force_default;
+	gchar *font_str;
+	GdkColor color;
+
+	width = gconf_client_get_int(stickynotes->gconf, GCONF_PATH "/defaults/width", NULL);
 	width = MAX (width, 1);
-	gint height = gconf_client_get_int(stickynotes->gconf, GCONF_PATH "/defaults/height", NULL);
+	height = gconf_client_get_int(stickynotes->gconf, GCONF_PATH "/defaults/height", NULL);
 	height = MAX (height, 1);
-	gboolean sys_color = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/use_system_color", NULL);
-	gboolean sys_font = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/use_system_font", NULL);
-	gint click_behavior = gconf_client_get_int(stickynotes->gconf, GCONF_PATH "/settings/click_behavior", NULL);
-	gboolean sticky = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/sticky", NULL);
-	gboolean force_default = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/force_default", NULL);
-	gchar *font_str = gconf_client_get_string(stickynotes->gconf, GCONF_PATH "/defaults/font", NULL);
+	sys_color = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/use_system_color", NULL);
+	sys_font = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/use_system_font", NULL);
+	click_behavior = gconf_client_get_int(stickynotes->gconf, GCONF_PATH "/settings/click_behavior", NULL);
+	sticky = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/sticky", NULL);
+	force_default = gconf_client_get_bool(stickynotes->gconf, GCONF_PATH "/settings/force_default", NULL);
+	font_str = gconf_client_get_string(stickynotes->gconf, GCONF_PATH "/defaults/font", NULL);
 	if (!font_str)
 		font_str = g_strdup ("Sans 10");
 	
-	GdkColor color;
 	{
 		gchar *color_str = gconf_client_get_string(stickynotes->gconf, GCONF_PATH "/defaults/color", NULL);
 		if (!color_str)
