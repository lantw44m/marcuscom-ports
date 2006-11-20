--- src/func.c.orig	Sun Nov 19 02:48:38 2006
+++ src/func.c	Mon Nov 20 01:27:26 2006
@@ -1037,11 +1037,11 @@
 	g_return_val_if_fail (ei != NULL, NULL);
 	g_return_val_if_fail (ei->func_call != NULL, NULL);
 
-	gnm_func_load_if_stub ((GnmFunc *)fn_def);
-
 	argc = ei->func_call->argc;
 	argv = ei->func_call->argv;
 	fn_def = ei->func_call->func;
+
+	gnm_func_load_if_stub ((GnmFunc *)fn_def);
 
 	/* Functions that deal with ExprNodes */
 	if (fn_def->fn_type == GNM_FUNC_TYPE_NODES)
