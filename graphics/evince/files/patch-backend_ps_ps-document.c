--- backend/ps/ps-document.c.orig	Tue Feb 13 10:27:32 2007
+++ backend/ps/ps-document.c	Tue Feb 13 10:27:41 2007
@@ -33,6 +33,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <sys/wait.h>
+#include <sys/signal.h>
 #include <errno.h>
 
 #include "ps-document.h"
