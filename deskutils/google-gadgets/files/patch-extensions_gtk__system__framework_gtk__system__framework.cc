
$FreeBSD: ports/deskutils/google-gadgets/files/patch-extensions_gtk__system__framework_gtk__system__framework.cc,v 1.2 2009/01/15 12:11:25 miwi Exp $

--- extensions/gtk_system_framework/gtk_system_framework.cc.orig
+++ extensions/gtk_system_framework/gtk_system_framework.cc
@@ -137,7 +137,7 @@
         whole_title.c_str(), NULL, action,
         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
         GTK_STOCK_OK, GTK_RESPONSE_OK,
-        NULL);
+        (gint*)0);
     gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
 
     if (action == GTK_FILE_CHOOSER_ACTION_SAVE) {
