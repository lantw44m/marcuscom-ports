--- libgnomeui/gnome-icon-list.c.orig	Mon May 31 19:37:41 2004
+++ libgnomeui/gnome-icon-list.c	Mon May 31 19:38:19 2004
@@ -572,7 +572,7 @@
 void
 gnome_icon_list_select_all (GnomeIconList *gil)
 {
-	uint i;
+	guint i;
 	
 	g_return_if_fail (gil != NULL);
 	g_return_if_fail (IS_GIL (gil));
