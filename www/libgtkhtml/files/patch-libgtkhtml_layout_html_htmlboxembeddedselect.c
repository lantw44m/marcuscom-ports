--- libgtkhtml/layout/html/htmlboxembeddedselect.c.orig	Sun Dec 22 16:16:43 2002
+++ libgtkhtml/layout/html/htmlboxembeddedselect.c	Sun Dec 22 16:17:19 2002
@@ -149,8 +149,9 @@
 	DomHTMLSelectElement *select_node;
 
 	if (box->dom_node) {
+		GtkTreeModel *model;
 		select_node = DOM_HTML_SELECT_ELEMENT (box->dom_node);
-		GtkTreeModel *model = dom_html_select_element_get_tree_model (select_node);
+		model =  dom_html_select_element_get_tree_model (select_node);
 
 		if (dom_HTMLSelectElement__get_multiple (select_node) == FALSE &&
 	            dom_HTMLSelectElement__get_size (select_node) == 1) {
