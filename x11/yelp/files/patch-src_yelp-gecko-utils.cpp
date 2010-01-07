--- src/yelp-gecko-utils.cpp.orig	2010-01-07 15:44:16.000000000 -0500
+++ src/yelp-gecko-utils.cpp	2010-01-07 15:46:48.000000000 -0500
@@ -28,7 +28,9 @@
 #include <nsStringAPI.h>
 
 #ifdef HAVE_GECKO_1_9
+#define XPCOM_GLUE 1
 #include <gtkmozembed_glue.cpp>
+#undef XPCOM_GLUE
 #endif
 
 #include <gtkmozembed.h>
