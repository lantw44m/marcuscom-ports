--- calendar/libedata-cal/e-cal-backend-intervaltree.c.orig	2013-05-06 19:20:48.000000000 +0000
+++ calendar/libedata-cal/e-cal-backend-intervaltree.c	2013-05-06 19:20:57.000000000 +0000
@@ -26,7 +26,7 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "e-cal-backend-intervaltree.h"
 
