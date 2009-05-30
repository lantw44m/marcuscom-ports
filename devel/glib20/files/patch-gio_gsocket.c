--- gio/gsocket.c.orig	2009-05-30 11:38:20.000000000 +0200
+++ gio/gsocket.c	2009-05-30 11:40:17.000000000 +0200
@@ -40,6 +40,7 @@
 # include <fcntl.h>
 # include <unistd.h>
 # include <sys/types.h>
+# include <sys/socket.h>
 #else
 # include <winsock2.h>
 # include <mswsock.h>
