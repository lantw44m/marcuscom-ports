--- src/math-equation.c.orig	2011-05-30 19:16:53.000000000 -0400
+++ src/math-equation.c	2011-05-30 19:19:35.000000000 -0400
@@ -1305,6 +1305,7 @@ void
 math_equation_solve(MathEquation *equation)
 {
     GError *error = NULL;
+    gulong stacksize = 0;
 
     g_return_if_fail(equation != NULL);
 
@@ -1326,7 +1327,13 @@ math_equation_solve(MathEquation *equati
 
     math_equation_set_number_mode(equation, NORMAL);
 
-    g_thread_create(math_equation_solve_real, equation, false, &error);
+    if (GLIB_SIZEOF_LONG == 8) {
+	    stacksize = 0x400000;
+    } else {
+	    stacksize = 0x200000;
+    }
+
+    g_thread_create_full(math_equation_solve_real, equation, stacksize, false, false, G_THREAD_PRIORITY_NORMAL, &error);
 
     if (error)
         g_warning("Error spawning thread for calculations: %s\n", error->message);
