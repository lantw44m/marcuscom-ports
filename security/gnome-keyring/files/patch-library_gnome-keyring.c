--- library/gnome-keyring.c.orig	2008-02-26 20:04:07.000000000 -0600
+++ library/gnome-keyring.c	2008-02-26 20:04:11.000000000 -0600
@@ -1786,6 +1786,7 @@
 	GnomeKeyringResult res;
 	gchar **daemonenv, **e;
 	gchar **parts;
+	extern char **environ;
 
 	gkr_buffer_init_full (&send, 128, NORMAL_ALLOCATOR);
 
