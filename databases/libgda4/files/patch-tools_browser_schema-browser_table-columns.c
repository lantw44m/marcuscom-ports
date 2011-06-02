--- tools/browser/schema-browser/table-columns.c.orig	2011-06-02 16:36:04.000000000 +0200
+++ tools/browser/schema-browser/table-columns.c	2011-06-02 16:38:00.000000000 +0200
@@ -117,12 +117,14 @@
 {
 	TableColumns *tcolumns = (TableColumns *) widget;
         GTK_WIDGET_CLASS (parent_class)->show_all (widget);
+#ifdef HAVE_LDAP
 	if (browser_connection_is_ldap (tcolumns->priv->bcnc)) {
 		if (! tcolumns->priv->ldap_props_shown) {
 			gtk_widget_hide (tcolumns->priv->ldap_header);
 			gtk_widget_hide (tcolumns->priv->ldap_text);
 		}
 	}
+#endif
 }
 
 GType
