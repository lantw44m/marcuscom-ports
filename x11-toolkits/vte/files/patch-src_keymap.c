--- src/keymap.c.orig	Tue Oct 22 17:42:20 2002
+++ src/keymap.c	Tue Oct 22 17:42:33 2002
@@ -18,6 +18,7 @@
 
 #ident "$Id: patch-src_keymap.c,v 1.17 2008-08-06 02:25:09 marcus Exp $"
 #include "../config.h"
+#include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
 #include <glib.h>
