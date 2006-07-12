--- gnomevfs/vfsmodule.c.orig	Wed Jul 12 17:42:39 2006
+++ gnomevfs/vfsmodule.c	Wed Jul 12 17:41:07 2006
@@ -7,6 +7,7 @@
 #include <libgnomevfs/gnome-vfs-resolve.h>
 #include <libgnomevfs/gnome-vfs-dns-sd.h>
 #include <libgnomevfs/gnome-vfs-async-ops.h>
+#include <bonobo-activation/bonobo-activation.h>
 #include <pyorbit.h>
 
 static GHashTable *monitor_hash;
