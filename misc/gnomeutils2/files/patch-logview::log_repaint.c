
$FreeBSD: ports/misc/gnomeutils2/files/patch-logview::log_repaint.c,v 1.2 2003/02/07 18:42:09 marcus Exp $

--- logview/log_repaint.c	2001/11/23 16:01:55	1.1
+++ logview/log_repaint.c	2001/11/23 16:02:30
@@ -24,7 +24,9 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <gnome.h>
 #include "logview.h"
