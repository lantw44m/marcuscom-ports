--- gst/interleave/deinterleave.c.orig	Thu Feb 26 19:41:29 2004
+++ gst/interleave/deinterleave.c	Thu Feb 26 19:41:38 2004
@@ -379,7 +379,7 @@
   }
 
   if (this->channels == 0) {
-    GST_ELEMENT_ERROR (this, CORE, NEGOTIATION, NULL,
+    GST_ELEMENT_ERROR (this, CORE, NEGOTIATION, (NULL),
                        ("format wasn't negotiated before chain function"));
     return;
   } else if (this->channels == 1) {
