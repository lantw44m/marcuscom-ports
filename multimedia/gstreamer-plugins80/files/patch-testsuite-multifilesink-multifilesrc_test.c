--- multifilesrc_test.c.orig	Tue Nov 23 23:46:51 2004
+++ multifilesrc_test.c	Tue Nov 23 23:47:18 2004
@@ -3,7 +3,6 @@
 int
 main (int argc, char **argv)
 {
-  gst_init (&argc, &argv);
 
   GSList *locations;
   int i;
@@ -11,6 +10,8 @@
   //gboolean retval;
 
   GstElement *pipeline, *src, *sink;
+
+  gst_init (&argc, &argv);
 
   g_print ("creating sink\n");
   sink = gst_element_factory_make ("multifilesink", "sink");
