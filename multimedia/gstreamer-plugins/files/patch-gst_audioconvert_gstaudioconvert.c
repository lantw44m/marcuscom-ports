--- gst/audioconvert/gstaudioconvert.c.orig	Thu Feb 26 19:35:40 2004
+++ gst/audioconvert/gstaudioconvert.c	Thu Feb 26 19:36:33 2004
@@ -242,7 +242,7 @@
 
   if (!gst_pad_is_negotiated (this->sink))
   {
-    GST_ELEMENT_ERROR (this, CORE, NEGOTIATION, NULL,
+    GST_ELEMENT_ERROR (this, CORE, NEGOTIATION, (NULL),
                        ("Sink pad not negotiated before chain function"));
     return;
   }
