
$FreeBSD: ports/multimedia/xmps/files/patch-system::mpeg3::mpeg3io.c,v 1.1 2001/02/04 22:01:32 sobomax Exp $

--- system/mpeg3/mpeg3io.c.orig	Fri Nov  3 21:41:37 2000
+++ system/mpeg3/mpeg3io.c	Sun Feb  4 22:55:34 2001
@@ -20,7 +20,6 @@
 #include "mpeg3protos.h"
 
 #include <stdio.h>
-#include <mntent.h>
 #include <sys/stat.h>
 #include <stdlib.h>
 #include <string.h>
