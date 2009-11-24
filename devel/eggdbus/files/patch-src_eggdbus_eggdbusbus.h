--- src/eggdbus/eggdbusbus.h.orig	2009-11-23 20:37:48.000000000 -0500
+++ src/eggdbus/eggdbusbus.h	2009-11-23 20:38:26.000000000 -0500
@@ -7,6 +7,8 @@
 #ifndef __EGG_DBUS_BUS_H
 #define __EGG_DBUS_BUS_H
 
+#include <unistd.h>
+
 #include <glib-object.h>
 #include <gio/gio.h>
 #include <eggdbus/eggdbustypes.h>
