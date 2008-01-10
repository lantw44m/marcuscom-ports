--- bus/bus.c.orig	2007-07-24 14:39:55.000000000 -0400
+++ bus/bus.c	2008-01-10 17:26:49.000000000 -0500
@@ -21,6 +21,8 @@
  *
  */
 
+#include <errno.h>
+#include <signal.h>
 #include "bus.h"
 #include "activation.h"
 #include "connection.h"
@@ -749,7 +751,9 @@ bus_context_new (const DBusString *confi
         }
 
       bytes = _dbus_string_get_length (&pid);
-      if (_dbus_pipe_write (print_pid_pipe, &pid, 0, bytes, error) != bytes)
+      signal (SIGPIPE, SIG_IGN);
+      if (_dbus_pipe_write (print_pid_pipe, &pid, 0, bytes, error) != bytes &&
+	  errno != EPIPE)
         {
           /* pipe_write sets error on failure but not short write */
           if (error != NULL && !dbus_error_is_set (error))
@@ -758,6 +762,7 @@ bus_context_new (const DBusString *confi
                               "Printing message bus PID: did not write enough bytes\n");
             }
           _dbus_string_free (&pid);
+          signal (SIGPIPE, SIG_DFL);
           goto failed;
         }
 
