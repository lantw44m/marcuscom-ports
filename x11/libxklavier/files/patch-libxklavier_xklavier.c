--- libxklavier/xklavier.c.orig	Tue Nov 23 18:32:29 2004
+++ libxklavier/xklavier.c	Tue Nov 23 18:32:48 2004
@@ -700,9 +700,10 @@
 {
   if ( xklVTable == NULL )
   {
+    char *p;
     XklDebug( 0, "ERROR: XKL VTable is NOT initialized.\n" );
     /* force the crash! */
-    char *p = NULL; *p = '\0';
+    p = NULL; *p = '\0';
   }
 }
 
