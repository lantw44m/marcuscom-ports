--- ext/shout/gstshout.c.orig	Tue Nov 25 19:09:41 2003
+++ ext/shout/gstshout.c	Tue Nov 25 20:11:54 2003
@@ -109,7 +109,7 @@
   if (!icecastsend_type) {
     static const GTypeInfo icecastsend_info = {
       sizeof (GstIcecastSendClass),
-      (GBaseInitFunc gst_icecastsend_base_init, NULL,
+      (GBaseInitFunc) gst_icecastsend_base_init, NULL,
       (GClassInitFunc) gst_icecastsend_class_init, NULL, NULL,
       sizeof (GstIcecastSend), 0,
       (GInstanceInitFunc) gst_icecastsend_init,
