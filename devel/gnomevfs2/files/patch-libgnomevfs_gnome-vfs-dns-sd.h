--- libgnomevfs/gnome-vfs-dns-sd.h.orig	Fri Jun 18 13:26:28 2004
+++ libgnomevfs/gnome-vfs-dns-sd.h	Fri Jun 18 13:26:45 2004
@@ -24,6 +24,7 @@
 #ifndef GNOME_VFS_DNS_SD_H
 #define GNOME_VFS_DSN_SD_H
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <glib.h>
 #include <libgnomevfs/gnome-vfs-result.h>
