--- openfiles.cpp.orig	Thu Dec 14 17:49:02 2006
+++ openfiles.cpp	Fri Dec 22 13:49:23 2006
@@ -6,6 +6,7 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 #include "procman.h"
@@ -53,7 +54,11 @@ friendlier_hostname(const char *dotted_q
 		goto failsafe;
 
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 601103
+	host = gethostbyaddr((char *) &addr4, sizeof addr4, AF_INET);
+#else
 	host = gethostbyaddr(&addr4, sizeof addr4, AF_INET);
+#endif
 
 	if(!host)
 		goto failsafe;
