--- src/yelp-window.c.orig	Tue Dec 30 13:24:05 2003
+++ src/yelp-window.c	Tue Dec 30 13:24:34 2003
@@ -1029,11 +1029,12 @@
     YelpWindow *window = YELP_WINDOW (user_data);
     YelpURI    *uri;
     GError     *error = NULL;
+    gchar      *frag, *page;
 
     uri  = yelp_window_get_current_uri (window);
 
-    gchar *frag = yelp_uri_get_fragment (uri);
-    gchar *page = yelp_pager_resolve_uri (pager, uri);
+    frag = yelp_uri_get_fragment (uri);
+    page = yelp_pager_resolve_uri (pager, uri);
 
     if (!page && (frag && strcmp (frag, ""))) {
 	gchar *frag_id = yelp_uri_get_fragment (uri);
