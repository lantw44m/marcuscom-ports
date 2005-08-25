--- calendar/libical/src/libical/vsnprintf.c.orig	Thu Aug 25 18:11:34 2005
+++ calendar/libical/src/libical/vsnprintf.c	Thu Aug 25 18:11:44 2005
@@ -1,6 +1,6 @@
+#include "config.h"
 #if !defined(WIN32) && !defined(HAVE_SNPRINTF)
 
-#include "config.h"
 
 /*
  * Revision 12: http://theos.com/~deraadt/snprintf.c
