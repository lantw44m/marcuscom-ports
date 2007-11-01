--- gnome-settings-daemon/gnome-settings-multimedia-keys.c.orig	2007-09-18 05:32:43.000000000 -0400
+++ gnome-settings-daemon/gnome-settings-multimedia-keys.c	2007-11-01 08:29:46.987143617 -0400
@@ -610,7 +610,7 @@
 	if ((command != NULL) && (strcmp (command, "") != 0))
 		execute (acme, command, FALSE, FALSE);
 	else
-		execute (acme, "eject -T", FALSE, FALSE);
+		execute (acme, "gnome-eject -b --device=%%CDROM%%", FALSE, FALSE);
 
 	g_free (command);
 }
@@ -708,7 +708,7 @@
 		do_mail_action (acme);
 		break;
 	case SLEEP_KEY:
-		do_sleep_action ("apm", "xset dpms force off");
+		do_sleep_action ("zzz", "xset dpms force off");
 		break;
 	case SCREENSAVER_KEY:
 		if ((cmd = g_find_program_in_path ("gnome-screensaver-command")))
