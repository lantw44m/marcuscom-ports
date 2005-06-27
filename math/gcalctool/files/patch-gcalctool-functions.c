--- gcalctool/functions.c.orig	Mon Jun 27 20:14:54 2005
+++ gcalctool/functions.c	Mon Jun 27 20:16:22 2005
@@ -570,9 +570,6 @@
 do_tfunc(int s[MP_SIZE], int t[MP_SIZE], enum trig_func tfunc)
 {
     // Assumes the SIN=0, COS=1, TAN=2
-    
-    assert(tfunc < 3); 
-    
     enum trig_func conv_table[3][4] = {
 	{sin_t, asin_t, sinh_t, asinh_t},
 	{cos_t, acos_t, cosh_t, acosh_t},
@@ -582,7 +579,9 @@
     int inverse = (v->inverse) ? 1 : 0;
     int hyperbolic = (v->hyperbolic) ? 2 : 0;
     int mode = (inverse | hyperbolic);
-    
+
+    assert(tfunc < 3); 
+ 
     if (!v->current) return -EINVAL;
     
     calc_trigfunc(conv_table[tfunc][mode], s, t);
