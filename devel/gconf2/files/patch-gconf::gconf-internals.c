
$FreeBSD: ports/devel/gconf2/files/patch-gconf::gconf-internals.c,v 1.2 2002/02/16 09:13:28 sobomax Exp $

--- gconf/gconf-internals.c	2002/02/15 19:13:07	1.1
+++ gconf/gconf-internals.c	2002/02/15 19:13:32
@@ -26,6 +26,9 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
