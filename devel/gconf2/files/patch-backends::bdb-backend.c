
$FreeBSD: ports/devel/gconf2/files/patch-backends::bdb-backend.c,v 1.2 2002/02/16 09:13:28 sobomax Exp $

--- backends/bdb-backend.c	2002/02/15 19:10:46	1.1
+++ backends/bdb-backend.c	2002/02/15 19:11:25
@@ -29,10 +29,9 @@
 #include <gconf/gconf-internals.h>
 #include <gconf/gconf.h>
 
+#include "config.h"
 #include "bdb.h"
 #include "dir-utils.h"
-
-#include <db.h>
 
 #include <stdio.h>
 #include <time.h>
