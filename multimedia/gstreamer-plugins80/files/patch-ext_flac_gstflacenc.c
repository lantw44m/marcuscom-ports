--- ext/flac/gstflacenc.c.orig	Fri Feb  6 15:43:38 2004
+++ ext/flac/gstflacenc.c	Fri Feb  6 16:15:23 2004
@@ -575,7 +575,7 @@
     gst_flacenc_set_metadata (flacenc);
     state = FLAC__seekable_stream_encoder_init (flacenc->encoder);
     if (state != FLAC__STREAM_ENCODER_OK) {
-      GST_ELEMENT_ERROR (flacenc, LIBRARY, INIT, NULL,
+      GST_ELEMENT_ERROR (flacenc, LIBRARY, INIT, (NULL),
 		         ("could not initialize encoder (wrong parameters?)"));
       return;
     }
@@ -610,7 +610,7 @@
   flacenc->data = NULL;
 
   if (!res) {
-    GST_ELEMENT_ERROR (flacenc, STREAM, ENCODE, NULL, NULL);
+    GST_ELEMENT_ERROR (flacenc, STREAM, ENCODE, (NULL), (NULL));
   }
 }
 
