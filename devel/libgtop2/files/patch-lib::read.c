--- lib/read.c.orig	Fri Jun 18 04:03:55 2004
+++ lib/read.c	Tue Jul 20 21:46:23 2004
@@ -22,6 +22,7 @@
 */
 
 #include <config.h>
+#include <errno.h>
 #include <glibtop/read.h>
 #include "libgtop-i18n.h"
 
@@ -56,10 +57,13 @@
 	fprintf (stderr, "LIBRARY: really reading %d bytes.\n", size);
 #endif
 
+retry:
 	if (server->socket) {
 		do_read (server->socket, buf, size);
 	} else {
 		if(read (server->input [0], buf, size) < 0)
+			if (errno == EINTR)
+				goto retry;
 			glibtop_error_io_r (
 				server,
 				ngettext ("read %d byte",
