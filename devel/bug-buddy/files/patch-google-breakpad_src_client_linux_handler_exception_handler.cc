--- google-breakpad/src/client/linux/handler/exception_handler.cc.orig	2007-08-02 01:59:39.000000000 -0400
+++ google-breakpad/src/client/linux/handler/exception_handler.cc	2007-08-02 02:00:19.000000000 -0400
@@ -133,7 +133,7 @@ void ExceptionHandler::SetupHandler() {
   // Signal on a different stack to avoid using the stack
   // of the crashing thread.
   struct sigaltstack sig_stack;
-  sig_stack.ss_sp = malloc(MINSIGSTKSZ);
+  sig_stack.ss_sp = (char *) malloc(MINSIGSTKSZ);
   if (sig_stack.ss_sp == NULL)
     return;
   sig_stack.ss_size = MINSIGSTKSZ;
