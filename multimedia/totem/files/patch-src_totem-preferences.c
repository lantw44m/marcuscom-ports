--- src/totem-preferences.c.orig	Mon Jan  3 00:18:39 2005
+++ src/totem-preferences.c	Sun Jan 23 12:06:53 2005
@@ -24,7 +24,7 @@
 #include <stdio.h>
 #include <sys/stat.h>
 #include <sys/types.h>
-#include <bacon-cd-selection.h>
+#include <nautilus-burn-drive-selection.h>
 
 #include "totem.h"
 #include "totem-private.h"
@@ -210,11 +210,11 @@
 }
 
 static void
-on_combo_entry1_changed (BaconCdSelection *bcs, char *device, Totem *totem)
+on_combo_entry1_changed (NautilusBurnDriveSelection *bcs, char *device, Totem *totem)
 {
 	const char *str;
 
-	str = bacon_cd_selection_get_device (bcs);
+	str = nautilus_burn_drive_selection_get_device (bcs);
 	gconf_client_set_string (totem->gc, GCONF_PREFIX"/mediadev", str, NULL);
 	bacon_video_widget_set_media_device
 		(BACON_VIDEO_WIDGET (totem->bvw), str);
@@ -271,9 +271,9 @@
 			GCONF_PREFIX"/mediadev", NULL);
 
 	if (mediadev == NULL || strcmp (mediadev, "") == 0)
-		mediadev = g_strdup ("/dev/cdrom");
+		mediadev = g_strdup ("/dev/acd0");
 
-	bacon_cd_selection_set_device (BACON_CD_SELECTION (item), mediadev);
+	nautilus_burn_drive_selection_set_device (NAUTILUS_BURN_DRIVE_SELECTION (item), mediadev);
 	bacon_video_widget_set_media_device
 		(BACON_VIDEO_WIDGET (totem->bvw), mediadev);
 
@@ -358,7 +358,7 @@
 {
 	GtkWidget *widget;
 
-	widget = bacon_cd_selection_new ();
+	widget = nautilus_burn_drive_selection_new ();
 	gtk_widget_show (widget);
 
 	return widget;
@@ -480,8 +480,8 @@
 	if (mediadev == NULL || (strcmp (mediadev, "") == 0)
 			|| (strcmp (mediadev, "auto") == 0))
 	{
-		mediadev = g_strdup (bacon_cd_selection_get_default_device
-				     (BACON_CD_SELECTION (item)));
+		mediadev = g_strdup (nautilus_burn_drive_selection_get_default_device
+				     (NAUTILUS_BURN_DRIVE_SELECTION (item)));
 		gconf_client_set_string (totem->gc, GCONF_PREFIX"/mediadev",
 				mediadev, NULL);
 	}
@@ -491,7 +491,7 @@
 	g_signal_connect (G_OBJECT (item), "device-changed",
 			G_CALLBACK (on_combo_entry1_changed), totem);
 
-	bacon_cd_selection_set_device (BACON_CD_SELECTION (item), mediadev);
+	nautilus_burn_drive_selection_set_device (NAUTILUS_BURN_DRIVE_SELECTION (item), mediadev);
 	g_free (mediadev);
 
 	/* Connection Speed */
