--- src/mapping-protocol.c.orig	Sun Aug 20 08:47:20 2006
+++ src/mapping-protocol.c	Tue Aug 22 01:28:24 2006
@@ -26,6 +26,8 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/time.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
