--- eplugin/exchange-operations.c.orig	2010-03-13 03:42:59.000000000 -0500
+++ eplugin/exchange-operations.c	2010-03-13 03:43:52.000000000 -0500
@@ -304,3 +304,15 @@ is_exchange_personal_folder (ExchangeAcc
 	}
 	return FALSE;
 }
+
+const char * g_module_check_init (gpointer module);
+const char *
+g_module_check_init (gpointer module) {
+	return NULL;
+}
+
+void g_module_unload (gpointer module);
+void
+g_module_unload (gpointer module) {
+	return;
+}
