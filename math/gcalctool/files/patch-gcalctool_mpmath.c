--- gcalctool/mpmath.c.orig	Mon Jul 26 22:16:10 2004
+++ gcalctool/mpmath.c	Mon Jul 26 22:16:46 2004
@@ -750,17 +750,18 @@
    * boolean means BINARY representation
    */
 
-    assert(times >= 0);
-
     double dval;
+    BOOLEAN temp;
     mpcmd(s, &dval);
-    BOOLEAN temp = ibool(dval);
+    temp = ibool(dval);
 
     /* There is a reason to do shift like this. Reason is that
      * processors define shift only in a certain range. i386 uses only 5
      * bits to describe shiftable amount. So, shift 32 times gives original
      * number. That can cause very strange results (and bugs).
      */
+
+    assert(times >= 0);
 
     while (times--) {
         temp = (dir == right) ? temp >> 1 : temp << 1;
