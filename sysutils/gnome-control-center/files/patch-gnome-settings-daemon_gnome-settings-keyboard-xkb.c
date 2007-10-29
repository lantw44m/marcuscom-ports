--- gnome-settings-daemon/gnome-settings-keyboard-xkb.c.orig	2007-10-29 08:19:27.351818736 -0400
+++ gnome-settings-daemon/gnome-settings-keyboard-xkb.c	2007-10-29 08:19:52.087524252 -0400
@@ -35,7 +35,6 @@
 #include <string.h>
 #include <time.h>
 
-#include <libgnomekbd/gkbd-config-registry.h>
 #include <libgnomekbd/gkbd-desktop-config.h>
 #include <libgnomekbd/gkbd-keyboard-config.h>
 
@@ -392,7 +391,6 @@
 void
 gnome_settings_keyboard_xkb_init (GConfClient * client)
 {
-	GObject *reg = NULL;
 #ifdef GSDKX
 	xkl_set_debug_level (200);
 	logfile = fopen ("/tmp/gsdkx.log", "a");
@@ -425,8 +423,6 @@
 					 XKLL_MANAGE_LAYOUTS |
 					 XKLL_MANAGE_WINDOW_STATES);
 
-		reg =
-		    g_object_new (gkbd_config_registry_get_type (), NULL);
 	}
 }
 
