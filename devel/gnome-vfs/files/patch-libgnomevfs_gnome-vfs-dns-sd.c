--- libgnomevfs/gnome-vfs-dns-sd.c.orig	Fri Jun 18 13:20:41 2004
+++ libgnomevfs/gnome-vfs-dns-sd.c	Fri Jun 18 13:21:20 2004
@@ -24,6 +24,9 @@
 #include <config.h>
 
 #include <sys/time.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #include <string.h>
 #include "gnome-vfs-dns-sd.h"
