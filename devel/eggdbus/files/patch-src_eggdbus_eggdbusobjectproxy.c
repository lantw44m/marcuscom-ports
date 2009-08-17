--- src/eggdbus/eggdbusobjectproxy.c.orig	2009-08-01 11:00:39.000000000 +0200
+++ src/eggdbus/eggdbusobjectproxy.c	2009-08-01 11:00:50.000000000 +0200
@@ -22,6 +22,7 @@
 #include "config.h"
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <dbus/dbus.h>
 #include <eggdbus/eggdbusobjectproxy.h>
 #include <eggdbus/eggdbusinterfaceproxy.h>
