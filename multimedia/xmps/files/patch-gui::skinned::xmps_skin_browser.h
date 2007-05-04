
$FreeBSD: ports/multimedia/xmps/files/patch-gui::skinned::xmps_skin_browser.h,v 1.1 2001/02/04 22:01:32 sobomax Exp $

--- gui/skinned/xmps_skin_browser.h.orig	Thu Nov 23 16:06:40 2000
+++ gui/skinned/xmps_skin_browser.h	Sun Feb  4 22:55:34 2001
@@ -36,7 +36,7 @@
 /* INCLUDES */
 
 #include <gtk/gtk.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <sys/stat.h>
 #include "libxmps/libxmps.h"
 #include "libxmpsutils/libxmpsutils.h"
