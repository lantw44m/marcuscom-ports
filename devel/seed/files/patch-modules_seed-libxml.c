--- modules/libxml/seed-libxml.c.orig	2010-01-07 19:10:50.000000000 -0500
+++ modules/libxml/seed-libxml.c	2010-01-07 19:11:18.000000000 -0500
@@ -449,7 +449,8 @@ seed_xml_xpathobj_get_value (SeedContext
 
 
 seed_static_function doc_funcs[] = {
-  {"xpathNewContext", seed_xml_construct_xpath_context, 0}
+  {"xpathNewContext", seed_xml_construct_xpath_context, 0},
+  {NULL, NULL, 0}
 };
 
 seed_static_value doc_values[] = {
