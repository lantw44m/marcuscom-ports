--- src/yelp-document.c.orig	2008-09-11 20:20:59.000000000 -0400
+++ src/yelp-document.c	2008-09-11 20:20:40.000000000 -0400
@@ -748,6 +749,13 @@ request_idle_final (YelpDocument *docume
     priv = document->priv;
 
     g_mutex_lock (priv->mutex);
+
+    if (priv->reqs_pending == NULL) {
+	    /*
+	       Time to bail as we shouldn't be here anyway.
+	    */
+	    return FALSE;
+    }
     
     for (cur = priv->reqs_pending; cur; cur = cur->next) {
 	request = cur->data;
