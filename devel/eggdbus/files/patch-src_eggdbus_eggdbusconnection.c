--- src/eggdbus/eggdbusconnection.c.orig	2009-08-01 10:59:42.000000000 +0200
+++ src/eggdbus/eggdbusconnection.c	2009-08-01 11:00:00.000000000 +0200
@@ -22,6 +22,7 @@
 #include "config.h"
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <dbus/dbus.h>
 #include <dbus/dbus-glib-lowlevel.h>
 #include <eggdbus/eggdbusconnection.h>
