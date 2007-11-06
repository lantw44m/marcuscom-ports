--- gui/settings-daemon/plugins/xsettings/gdm-xsettings-manager.c.orig	2007-11-06 15:06:39.000000000 -0500
+++ gui/settings-daemon/plugins/xsettings/gdm-xsettings-manager.c	2007-11-06 15:07:16.000000000 -0500
@@ -21,6 +21,8 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/wait.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
