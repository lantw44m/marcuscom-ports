--- sys/xvideo/gstxvimage.c.orig	Fri Jul 25 15:29:21 2003
+++ sys/xvideo/gstxvimage.c	Fri Nov 14 16:27:24 2003
@@ -42,6 +42,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <machine/param.h>
 #include <sys/types.h>
 
 #if defined (HAVE_IPC_H) && defined (HAVE_SHM_H) && defined (HAVE_XSHM_H)
