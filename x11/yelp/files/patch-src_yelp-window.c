--- src/yelp-window.c.orig	Tue Dec  2 11:47:05 2003
+++ src/yelp-window.c	Tue Dec  2 11:47:16 2003
@@ -841,8 +841,8 @@
 static void
 window_disconnect (YelpWindow *window)
 {
-    g_return_if_fail (YELP_IS_WINDOW (window));
     YelpWindowPriv *priv = window->priv;
+    g_return_if_fail (YELP_IS_WINDOW (window));
 
     priv->loading = 0;
     if (priv->page_handler) {
