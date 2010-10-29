--- libtomboy/tomboykeybinder.c.orig	2010-10-29 12:34:51.000000000 +0200
+++ libtomboy/tomboykeybinder.c	2010-10-29 12:35:33.000000000 +0200
@@ -313,7 +313,8 @@ tomboy_keybinder_is_modifier (guint keyc
 	XModifierKeymap *mod_keymap;
 	gboolean retval = FALSE;
 
-	mod_keymap = XGetModifierMapping (gdk_display);
+	mod_keymap = XGetModifierMapping (
+		GDK_DISPLAY_XDISPLAY(gdk_display_get_default()));
 
 	map_size = 8 * mod_keymap->max_keypermod;
 
