--- libgnomevfs/gnome-vfs-dns-sd.c.orig	Fri Jun 18 05:20:48 2004
+++ libgnomevfs/gnome-vfs-dns-sd.c	Thu Jul  1 02:39:34 2004
@@ -24,6 +24,9 @@
 #include <config.h>
 
 #include <sys/time.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #include <string.h>
 #include "gnome-vfs-dns-sd.h"
@@ -684,8 +687,8 @@
 	    gpointer     callback_data)
 {
 	sw_discovery session;
-	session = callback_data;
 	sw_salt salt;
+	session = callback_data;
 
 	if (sw_discovery_salt (session, &salt) == SW_OKAY) {
 		sw_salt_lock (salt);
