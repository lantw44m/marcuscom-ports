--- gst/interleave/interleave.c.orig	Thu Feb 26 19:40:04 2004
+++ gst/interleave/interleave.c	Thu Feb 26 19:40:44 2004
@@ -25,7 +25,7 @@
 #include "config.h"
 #endif
 
-#include <alloca.h>
+#include <stdlib.h>
 #include <string.h>
 #include <gst/gst.h>
 #include <gst/audio/audio.h>
@@ -414,7 +414,7 @@
   data_in = alloca (this->numchannels * sizeof (gpointer));
   
   if (!this->channels) {
-    GST_ELEMENT_ERROR (element, CORE, PAD, NULL,
+    GST_ELEMENT_ERROR (element, CORE, PAD, (NULL),
                        ("interleave: at least one sink pad needs to be connected"));
     return;
   }
@@ -487,7 +487,7 @@
 static void
 interleave_bytestream_loop (GstElement *element)
 {
-  GST_ELEMENT_ERROR (element, CORE, NOT_IMPLEMENTED, NULL,
+  GST_ELEMENT_ERROR (element, CORE, NOT_IMPLEMENTED, (NULL),
                      ("interleave: unbuffered mode is not yet implemented"));
 
   /* Should look the same as the buffered loop, except that getting the data is
