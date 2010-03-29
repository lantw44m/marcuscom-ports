--- plparse/totem-pl-parser-podcast.c	2010-03-27 04:45:52.000000000 -0400
+++ plparse/totem-pl-parser-podcast.c.orig	2010-03-27 04:45:30.000000000 -0400
@@ -25,6 +25,7 @@
 #include <glib.h>
 
 #ifndef TOTEM_PL_PARSER_MINI
+#undef _LARGEFILE64_SOURCE
 #include <zlib.h>
 
 #include "xmlparser.h"
