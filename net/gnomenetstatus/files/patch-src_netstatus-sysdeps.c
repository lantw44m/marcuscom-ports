--- src/netstatus-sysdeps.c.orig	Wed Feb 18 18:20:48 2004
+++ src/netstatus-sysdeps.c	Wed Feb 18 18:21:02 2004
@@ -267,7 +267,7 @@
   *out_bytes   = -1;
 
   error = NULL;
-  command_line = g_strdup_printf ("/usr/bin/netstat netstat -n -I %s -b -f inet", iface);
+  command_line = g_strdup_printf ("/usr/bin/netstat -n -I %s -b -f inet", iface);
   if (!g_shell_parse_argv (command_line, NULL, &argv, &error))
     {
       error_message = g_strdup_printf (_("Could not parse command line '%s': %s"),
