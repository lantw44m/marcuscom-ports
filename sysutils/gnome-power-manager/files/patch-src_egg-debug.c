--- src/egg-debug.c.orig	2008-09-23 00:42:11.000000000 +0200
+++ src/egg-debug.c	2008-09-23 00:44:38.000000000 +0200
@@ -98,8 +98,10 @@ egg_debug_backtrace (void)
 	char **symbols;
 	int i = 1;
 
-	call_stack_size = backtrace (call_stack, G_N_ELEMENTS (call_stack));
+/*	call_stack_size = backtrace (call_stack, G_N_ELEMENTS (call_stack));
 	symbols = backtrace_symbols (call_stack, call_stack_size);
+*/
+	symbols = NULL;
 	if (symbols != NULL) {
 		pk_set_console_mode (CONSOLE_RED);
 		g_print ("Traceback:\n");
