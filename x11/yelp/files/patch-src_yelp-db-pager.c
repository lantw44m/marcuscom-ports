--- src/yelp-db-pager.c.orig	Wed Dec  3 12:37:53 2003
+++ src/yelp-db-pager.c	Wed Dec  3 12:42:28 2003
@@ -544,9 +544,9 @@
     xmlNodePtr cur;
 
     if (xml_is_info (node))
-	title = _("Titlepage");
+	title = g_strdup (_("Titlepage"));
     else if (node->parent->type == XML_DOCUMENT_NODE)
-	title = _("Contents");
+	title = g_strdup (_("Contents"));
     else {
 	for (cur = node->children; cur; cur = cur->next) {
 	    if (!xmlStrcmp (cur->name, (xmlChar *) "title")) {
@@ -564,7 +564,7 @@
     }
 
     if (!title)
-	title = _("Unknown");
+	title = g_strdup (_("Unknown"));
 
     return title;
 }
