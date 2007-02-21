--- src/cut-n-paste/gdm-queue.c.orig	Tue Jan 30 11:21:39 2007
+++ src/cut-n-paste/gdm-queue.c	Tue Feb 20 23:20:17 2007
@@ -32,6 +32,7 @@
 #include <sys/un.h>
 #include <errno.h>
 #include <stdio.h>
+#include <signal.h>
 
 #include "gdm-queue.h"
 
@@ -235,13 +236,14 @@ gboolean gdm_run_queue (void *dummy)
         addr.sun_family = AF_UNIX;
 
         if (fcntl (gdm_socket, F_SETFL, O_NONBLOCK) < 0) {
-          close_gdm_socket ();
-          return TRUE;
+	  VE_IGNORE_EINTR (close (gdm_socket));
+	  return FALSE;
         }
 
         if (connect (gdm_socket, (struct sockaddr *)&addr, sizeof (addr)) < 0) {
-          close_gdm_socket ();
-          return TRUE;
+	  g_warning ("Unable to connect to GDM socket: %s", GDM_SOCKET_FILENAME);
+	  VE_IGNORE_EINTR (close (gdm_socket));
+	  return FALSE;
         }
 
         gdm_send_command("VERSION");
