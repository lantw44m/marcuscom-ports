--- gtk/gtkiconcache.c.orig	Mon Nov 22 21:39:32 2004
+++ gtk/gtkiconcache.c	Mon Nov 22 21:39:53 2004
@@ -20,6 +20,8 @@
 #include <config.h>
 #include "gtkdebug.h"
 #include "gtkiconcache.h"
+#include <sys/types.h>
+#include <sys/stat.h>
 
 #ifdef HAVE_MMAP
 #include <sys/mman.h>
@@ -27,8 +29,6 @@
 #ifdef G_OS_WIN32
 #include <io.h>
 #endif
-#include <sys/types.h>
-#include <sys/stat.h>
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
