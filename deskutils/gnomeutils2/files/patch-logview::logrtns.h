
$FreeBSD: ports/deskutils/gnomeutils2/files/patch-logview::logrtns.h,v 1.4 2004/04/05 03:11:19 marcus Exp $

--- logview/logrtns.h	2001/11/23 16:04:00	1.1
+++ logview/logrtns.h	2001/11/23 16:04:14
@@ -24,7 +24,9 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
 #include <string.h>
 #include "logview.h"
 
