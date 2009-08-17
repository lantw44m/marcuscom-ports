--- src/eggdbus/eggdbus.h.orig	2009-08-01 10:58:38.000000000 +0200
+++ src/eggdbus/eggdbus.h	2009-08-01 10:59:09.000000000 +0200
@@ -26,6 +26,8 @@
 #error "EggDBus is unstable API and subject to change. You must define EGG_DBUS_I_KNOW_API_IS_SUBJECT_TO_CHANGE to acknowledge this before using EggDBus."
 #endif
 
+#include <unistd.h>
+
 #define _EGG_DBUS_INSIDE_EGG_DBUS_H 1
 #include <eggdbus/eggdbustypes.h>
 #include <eggdbus/eggdbusenumtypes.h>
