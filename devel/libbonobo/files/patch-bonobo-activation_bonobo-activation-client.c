--- bonobo-activation/bonobo-activation-client.c.orig	Wed Dec 10 11:53:32 2003
+++ bonobo-activation/bonobo-activation-client.c	Wed Dec 10 12:00:19 2003
@@ -197,6 +197,8 @@
         return result;
 }
 
+extern char **environ;
+
 void
 bonobo_activation_register_client (Bonobo_ActivationContext context,
                                    CORBA_Environment       *ev)
@@ -217,7 +219,7 @@
                 bonobo_activation_hostname_get ());
 
         /* send environment to activation server */
-        client_env._buffer = __environ;
+        client_env._buffer = environ;
         if (client_env._buffer) {
                 for (i = 0; client_env._buffer[i]; ++i);
                 client_env._length = i;
