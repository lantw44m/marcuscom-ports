--- gst/parse/lex._gst_parse_yy.c.orig	Fri Nov 14 15:41:20 2003
+++ gst/parse/lex._gst_parse_yy.c	Fri Nov 14 15:41:28 2003
@@ -20,7 +20,6 @@
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
-#include <stdint.h> /* May break IA64 test-noansi-r */
 
 /* end standard C headers. */
 
