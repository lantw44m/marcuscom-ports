--- gst/cothreads.c.orig	Tue Dec 31 23:28:32 2002
+++ gst/cothreads.c	Mon Jan 13 19:31:54 2003
@@ -37,16 +37,20 @@
 #include "gstlog.h"
 #include "gstutils.h"
 
+#ifdef HAVE_MAKECONTEXT
+#include <ucontext.h>
+#endif
+
 /* older glibc's have MAP_ANON instead of MAP_ANONYMOUS */
 #ifndef MAP_ANONYMOUS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
-#define STACK_SIZE 0x200000
+#define STACK_SIZE 0x100000
 
 #define COTHREAD_MAGIC_NUMBER 0xabcdef
 
-#define COTHREAD_MAXTHREADS 16
+#define COTHREAD_MAXTHREADS 8
 #define COTHREAD_STACKSIZE (STACK_SIZE/COTHREAD_MAXTHREADS)
 
 static void 	cothread_destroy 	(cothread_state *cothread);
