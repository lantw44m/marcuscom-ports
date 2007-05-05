--- common/gdm-common.c.orig	Sat May  5 01:16:25 2007
+++ common/gdm-common.c	Sat May  5 01:17:04 2007
@@ -25,6 +25,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <locale.h>
+#include <netinet/in.h>
 
 #ifdef HAVE_CRT_EXTERNS_H
 #include <crt_externs.h>
