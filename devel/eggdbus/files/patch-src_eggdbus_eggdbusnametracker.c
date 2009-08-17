--- src/eggdbus/eggdbusbusnametracker.c.orig	2009-08-01 11:02:04.000000000 +0200
+++ src/eggdbus/eggdbusbusnametracker.c	2009-08-01 11:02:15.000000000 +0200
@@ -22,6 +22,7 @@
 #include "config.h"
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <dbus/dbus.h>
 #include <eggdbus/eggdbusbusnametracker.h>
 #include <eggdbus/eggdbusconnection.h>
