$FreeBSD: ports/sysutils/xfce4-showdesktop-plugin/files/patch-panel-plugin::showdesktop.c,v 1.1 2004/01/10 17:36:28 petef Exp $

--- panel-plugin/showdesktop.c.orig	Wed Nov  5 12:06:04 2003
+++ panel-plugin/showdesktop.c	Sat Jan 10 11:21:40 2004
@@ -225,10 +225,11 @@
 static void
 plugin_free (Control *ctrl)
 {
+    gui *plugin;
     g_return_if_fail (ctrl != NULL);
     g_return_if_fail (ctrl->data != NULL);
 
-    gui *plugin = ctrl->data;
+    plugin = ctrl->data;
     g_free(plugin);
 }
 
