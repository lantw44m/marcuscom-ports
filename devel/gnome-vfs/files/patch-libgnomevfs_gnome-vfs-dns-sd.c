--- libgnomevfs/gnome-vfs-dns-sd.c.orig	Mon Jul  5 16:39:19 2004
+++ libgnomevfs/gnome-vfs-dns-sd.c	Mon Jul  5 16:39:33 2004
@@ -694,8 +694,8 @@
 	    gpointer     callback_data)
 {
 	sw_discovery session;
-	session = callback_data;
 	sw_salt salt;
+	session = callback_data;
 
 	if (sw_discovery_salt (session, &salt) == SW_OKAY) {
 		sw_salt_lock (salt);
