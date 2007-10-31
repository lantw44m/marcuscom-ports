--- gnome-settings-daemon/gnome-settings-multimedia-keys.c.orig	2007-09-18 05:32:43.000000000 -0400
+++ gnome-settings-daemon/gnome-settings-multimedia-keys.c	2007-10-31 16:01:14.953632933 -0400
@@ -31,6 +31,7 @@
 #include <glib/gi18n.h>
 #include <gdk/gdkx.h>
 #include <gtk/gtk.h>
+#include <nautilus-burn.h>
 
 #include "eggaccelerators.h"
 
@@ -609,9 +610,24 @@
 					   GCONF_MISC_DIR "/eject_command", NULL);
 	if ((command != NULL) && (strcmp (command, "") != 0))
 		execute (acme, command, FALSE, FALSE);
-	else
-		execute (acme, "eject -T", FALSE, FALSE);
+	else {
+		g_type_init ();
+		nautilus_burn_init ();
+		GList *drives, *drivelist;
+		NautilusBurnDriveMonitor *monitor;
+
+		monitor = nautilus_burn_get_drive_monitor ();
+		drives = nautilus_burn_drive_monitor_get_drives (monitor);
+
+		for (drivelist = drives; drivelist != NULL; drivelist = drivelist->next) {
+			NautilusBurnDrive *drive;
+			drive = drivelist->data;
 
+			nautilus_burn_drive_eject (drive);
+		}
+        	nautilus_burn_shutdown ();
+	}
+		
 	g_free (command);
 }
 
@@ -708,7 +724,7 @@
 		do_mail_action (acme);
 		break;
 	case SLEEP_KEY:
-		do_sleep_action ("apm", "xset dpms force off");
+		do_sleep_action ("zzz", "xset dpms force off");
 		break;
 	case SCREENSAVER_KEY:
 		if ((cmd = g_find_program_in_path ("gnome-screensaver-command")))
