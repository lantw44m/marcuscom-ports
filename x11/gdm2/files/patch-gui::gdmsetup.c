--- gui/gdmsetup.c.orig	Tue Jul 15 13:23:37 2003
+++ gui/gdmsetup.c	Thu Jul 17 00:57:18 2003
@@ -1550,13 +1550,14 @@
 	if (dir_exists (theme_dir, dir)) {
 		char *fname = g_filename_to_utf8 (dir, -1, NULL, NULL, NULL);
 		char *s;
+		GtkWidget *dlg;
 		GtkWidget *button;
 		/* FIXME: if exists already perhaps we could also have an
 		 * option to change the dir name */
 		s = g_strdup_printf (_("Theme directory '%s' seems to be already "
 				       "installed, install again anyway?"),
 				     fname);
-		GtkWidget *dlg =
+		dlg =
 			ve_hig_dialog_new
 			(GTK_WINDOW (fs),
 			 GTK_DIALOG_MODAL | 
@@ -1602,7 +1603,7 @@
 			success = TRUE;
 
 			/* HACK! */
-			cmd = g_strdup_printf ("/bin/chown -R root.root %s", quoted);
+			cmd = g_strdup_printf ("/usr/sbin/chown -R gdm:gdm %s", quoted);
 			system (cmd);
 			g_free (cmd);
 
