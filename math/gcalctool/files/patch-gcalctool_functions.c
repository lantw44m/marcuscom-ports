--- gcalctool/functions.c.orig	Mon Jul 26 22:13:14 2004
+++ gcalctool/functions.c	Mon Jul 26 22:15:30 2004
@@ -99,7 +99,6 @@
 
 char* 
 ch_trig(char *func) {
-    assert(func);
   
     struct ch {
         char *orig;
@@ -130,6 +129,8 @@
   
     struct ch *ch = NULL;
 
+    assert(func);
+
     switch (table) {
       case 0:
           break;
@@ -396,6 +397,7 @@
             int j = i+3;
             char *prefix = malloc(i+1);
             char *postfix = malloc(len-j+1);
+	    char *print;
 
             assert(prefix && postfix);
             memset(prefix, 0, i+1);
@@ -405,7 +407,7 @@
 
             ans = make_number(v->e.ans, v->base, TRUE, FALSE);
             assert(ans);
-            char *print = malloc(strlen(ans)+i+len-j+1);
+            print = malloc(strlen(ans)+i+len-j+1);
             sprintf(print, "%s%s%s", prefix, ans, postfix);
             free(prefix);
             free(postfix);
@@ -671,7 +673,6 @@
 int
 do_tfunc(int s[MP_SIZE], int t[MP_SIZE], enum trig_func tfunc)
 {
-    if (!v->current) return -EINVAL;
 
     enum mode {
         normal = 0,
@@ -680,8 +681,13 @@
         invhyp = 3,
     } mode;
 
-    int inverse = (v->inverse) ? inv : 0; 
-    int hyperbolic = (v->hyperbolic) ? hyp : 0; 
+    int inverse;
+    int hyperbolic;
+
+    if (!v->current) return -EINVAL;
+
+    inverse = (v->inverse) ? inv : 0;
+    hyperbolic = (v->hyperbolic) ? hyp : 0;
 
     mode = (inverse | hyperbolic);
 
