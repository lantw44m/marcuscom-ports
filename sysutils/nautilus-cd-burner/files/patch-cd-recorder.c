--- cd-recorder.c.orig	Tue May 27 12:57:00 2003
+++ cd-recorder.c	Tue May 27 12:57:07 2003
@@ -1,9 +1,9 @@
 #include "config.h"
 
+#include <unistd.h>
 #ifdef __FreeBSD__
 #include <sys/uio.h>
 #endif
-#include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
