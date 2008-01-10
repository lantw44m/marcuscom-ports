--- dbus/dbus-sysdeps-util-unix.c.orig	2007-07-24 11:39:09.000000000 -0400
+++ dbus/dbus-sysdeps-util-unix.c	2008-01-10 17:20:38.000000000 -0500
@@ -162,7 +162,9 @@ _dbus_become_daemon (const DBusString *p
 	    }
 	  
 	  bytes = _dbus_string_get_length (&pid);
-	  if (_dbus_pipe_write (print_pid_pipe, &pid, 0, bytes, error) != bytes)
+	  signal (SIGPIPE, SIG_IGN);
+	  if (_dbus_pipe_write (print_pid_pipe, &pid, 0, bytes, error) != bytes &&
+	      errno != EPIPE)
 	    {
               /* _dbus_pipe_write sets error only on failure, not short write */
               if (error != NULL && !dbus_error_is_set(error))
@@ -172,8 +174,10 @@ _dbus_become_daemon (const DBusString *p
                 }
 	      _dbus_string_free (&pid);
               kill (child_pid, SIGTERM);
+	      signal (SIGPIPE, SIG_DFL);
 	      return FALSE;
 	    }
+	  signal (SIGPIPE, SIG_DFL);
 	  
 	  _dbus_string_free (&pid);
 	}
