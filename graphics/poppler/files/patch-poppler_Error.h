--- poppler/Error.h.orig	Mon Jul  4 02:59:46 2005
+++ poppler/Error.h	Mon Jul  4 02:59:54 2005
@@ -14,6 +14,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdarg.h>
 #include "poppler-config.h"
 
 extern void CDECL error(int pos, char *msg, ...);
