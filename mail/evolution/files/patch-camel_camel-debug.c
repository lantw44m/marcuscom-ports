--- camel/camel-debug.c.orig	Mon Apr  5 22:06:03 2004
+++ camel/camel-debug.c	Mon Apr  5 22:06:48 2004
@@ -153,8 +153,6 @@
 	pthread_mutex_unlock(&debug_lock);
 }
 
-#include <sys/debugreg.h>
-
 #if 0
 static unsigned
 i386_length_and_rw_bits (int len, enum target_hw_bp_type type)
