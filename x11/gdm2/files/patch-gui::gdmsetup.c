--- gui/gdmsetup.c.orig	Fri Jun  6 19:34:07 2003
+++ gui/gdmsetup.c	Mon Jun 16 16:45:20 2003
@@ -1587,7 +1587,7 @@
 			success = TRUE;
 
 			/* HACK! */
-			cmd = g_strdup_printf ("/bin/chown -R root.root %s", quoted);
+			cmd = g_strdup_printf ("/usr/sbin/chown -R gdm:gdm %s", quoted);
 			system (cmd);
 			g_free (cmd);
 
