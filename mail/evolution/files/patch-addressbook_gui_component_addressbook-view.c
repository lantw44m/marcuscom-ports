--- addressbook/gui/component/addressbook-view.c.orig	Tue Aug  3 16:26:39 2004
+++ addressbook/gui/component/addressbook-view.c	Tue Aug  3 16:26:49 2004
@@ -714,7 +714,7 @@
 {
 	AddressbookViewPrivate *priv = view->priv;
 	ESource *selected_source;
-	const char *uid;;
+	const char *uid;
 	EditorUidClosure *closure;
 
 	selected_source =
