--- common/gdm-common-unknown-origin.h.orig	2007-11-02 15:08:43.000000000 -0400
+++ common/gdm-common-unknown-origin.h	2007-11-02 15:09:07.000000000 -0400
@@ -22,6 +22,7 @@
 #ifndef _GDM_COMMON_UNKNOWN_H
 #define _GDM_COMMON_UNKNOWN_H
 
+#include <sys/stat.h>
 #include <stdio.h>
 #include <errno.h>
 #include <glib.h>
