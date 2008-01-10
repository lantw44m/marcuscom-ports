--- dbus/dbus-sysdeps.c.orig	2008-01-10 17:23:24.000000000 -0500
+++ dbus/dbus-sysdeps.c	2008-01-10 17:24:28.000000000 -0500
@@ -182,10 +182,14 @@ _dbus_getenv (const char *varname)
  *
  * @returns #TRUE on success.
  */
+extern char **environ;
 dbus_bool_t
 _dbus_clearenv (void)
 {
-  return (clearenv () == 0);
+  if (environ != NULL)
+    environ[0] = NULL;
+
+ return TRUE;
 }
 
 /*
