--- src/burn-dialog.c.orig	Fri May 12 18:30:17 2006
+++ src/burn-dialog.c	Fri May 12 18:30:35 2006
@@ -45,7 +45,7 @@
 #include <gtk/gtklabel.h>
 
 #ifdef HAVE_LIBNOTIFY
-#include <libnotify/notifynotification.h>
+#include <libnotify/notification.h>
 #endif
 
 #include "utils.h"
