--- gst/gstqueue.c.orig	Mon Feb  2 12:56:53 2004
+++ gst/gstqueue.c	Wed Feb 11 09:46:17 2004
@@ -361,6 +361,10 @@
 {
   while (!g_queue_is_empty (queue->queue)) {
     GstData *data = g_queue_pop_head (queue->queue);
+    /* First loose the reference we added when putting that data in the queue */
+    gst_data_unref (data);
+    /* Then loose another reference because we are supposed to destroy that
+       data when flushing */
     gst_data_unref (data);
   }
   queue->timeval = NULL;
