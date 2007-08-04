--- src/yelp-transform.c.orig	2007-08-03 23:13:53.000000000 -0400
+++ src/yelp-transform.c	2007-08-03 23:16:24.000000000 -0400
@@ -30,6 +30,7 @@
 #include <libxml/parserInternals.h>
 #include <libxml/xinclude.h>
 #include <libxslt/xslt.h>
+#include <libexslt/exslt.h>
 #include <libxslt/templates.h>
 #include <libxslt/transform.h>
 #include <libxslt/extensions.h>
@@ -42,6 +43,8 @@
 
 #define YELP_NAMESPACE "http://www.gnome.org/yelp/ns"
 
+static gboolean exslt_registered = FALSE;
+
 static void      transform_run         (YelpTransform  *transform);
 static gboolean  transform_free        (YelpTransform  *transform);
 static void      transform_set_error   (YelpTransform  *transform,
@@ -116,6 +119,10 @@ yelp_transform_start (YelpTransform *tra
     transform->params = g_strdupv (params);
 
     transform->context->_private = transform;
+    if (!exslt_registered) {
+	    exsltRegisterAll();
+	    exslt_registered = TRUE;
+    }
     xsltRegisterExtElement (transform->context,
 			    BAD_CAST "document",
 			    BAD_CAST YELP_NAMESPACE,
