--- drivemount/drive-button.c.orig	Sun Jul  3 17:18:34 2005
+++ drivemount/drive-button.c	Sun Jul  3 17:23:33 2005
@@ -24,6 +24,7 @@
 #  include <config.h>
 #endif
 
+#include <string.h>
 #include "drive-button.h"
 #include <glib/gi18n.h>
 #include <gdk/gdkkeysyms.h>
@@ -641,11 +642,13 @@ run_command (DriveButton *self, const ch
 
 	GList *volumes;
 	GnomeVFSVolume *volume;
+	char *uri;
+	char *mount_path;
 
 	volumes = gnome_vfs_drive_get_mounted_volumes (self->drive);
 	volume = GNOME_VFS_VOLUME (volumes->data);
-	char *uri = gnome_vfs_volume_get_activation_uri (volume);
-	char *mount_path = gnome_vfs_get_local_path_from_uri (uri);
+	uri = gnome_vfs_volume_get_activation_uri (volume);
+	mount_path = gnome_vfs_get_local_path_from_uri (uri);
 	g_free (uri);
 
 	gnome_vfs_drive_get_display_name (self->drive);
@@ -725,6 +728,11 @@ drive_button_ensure_popup (DriveButton *
     char *display_name, *tmp, *label;
     int action;
     GtkWidget *item;
+    GList *volumes;
+    GnomeVFSVolume *volume = NULL;
+    GnomeVFSDeviceType volume_type;
+    GCallback callback;
+    const char *action_icon = GTK_STOCK_OPEN;
 
     if (self->popup_menu) return;
 
@@ -762,9 +770,7 @@ drive_button_ensure_popup (DriveButton *
 	}
     }
 
-	GList *volumes;
-	GnomeVFSVolume *volume = NULL;
-	GnomeVFSDeviceType volume_type = device_type;
+	volume_type = device_type;
 
 	volumes = gnome_vfs_drive_get_mounted_volumes (self->drive);
 	if (volumes != NULL)
@@ -801,8 +807,7 @@ drive_button_ensure_popup (DriveButton *
     g_free (display_name);
     display_name = tmp;
 
-	GCallback callback = G_CALLBACK (open_drive);
-	const char *action_icon = GTK_STOCK_OPEN;
+	callback = G_CALLBACK (open_drive);
 
 	switch (volume_type) {
 	case GNOME_VFS_DEVICE_TYPE_VIDEO_DVD:
