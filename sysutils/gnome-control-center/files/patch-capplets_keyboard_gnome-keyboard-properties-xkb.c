--- capplets/keyboard/gnome-keyboard-properties-xkb.c.orig	Thu Jan 13 02:47:53 2005
+++ capplets/keyboard/gnome-keyboard-properties-xkb.c	Thu Jan 13 02:48:01 2005
@@ -137,8 +137,8 @@
 void
 setup_xkb_tabs (GladeXML * dialog, GConfChangeSet * changeset)
 {
-  xkbGConfClient = gconf_client_get_default ();
   GObject * peditor;
+  xkbGConfClient = gconf_client_get_default ();
 
   XklInit (GDK_DISPLAY ());
   XklConfigInit ();
