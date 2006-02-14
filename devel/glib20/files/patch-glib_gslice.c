--- glib/gslice.c.orig	Tue Feb 14 11:45:19 2006
+++ glib/gslice.c	Tue Feb 14 11:46:37 2006
@@ -20,7 +20,8 @@
 
 #include "config.h"
 
-#ifdef HAVE_POSIX_MEMALIGN
+#if defined(HAVE_POSIX_MEMALIGN) && defined(POSIX_MEMALIGN_WITH_COMPLIANT_ALLOCS)
+#define HAVE_COMPLIANT_POSIX_MEMALIGN 1
 #define _XOPEN_SOURCE 600       /* posix_memalign() */
 #endif
 #include <stdlib.h>             /* posix_memalign() */
@@ -37,11 +38,6 @@
 #include <windows.h>
 #include <process.h>
 #endif
-
-#if     defined HAVE_POSIX_MEMALIGN && defined POSIX_MEMALIGN_WITH_COMPLIANT_ALLOCS
-#  define HAVE_COMPLIANT_POSIX_MEMALIGN 1
-#endif
-
 
 /* the GSlice allocator is split up into 4 layers, roughly modelled after the slab
  * allocator and magazine extensions as outlined in:
