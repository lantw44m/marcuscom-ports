--- ps/ps-document.c.orig	Sat Feb 26 17:36:03 2005
+++ ps/ps-document.c	Sat Feb 26 17:38:26 2005
@@ -487,12 +487,12 @@
   GdkColor white = { 0, 0xFFFF, 0xFFFF, 0xFFFF };   /* pixel, r, g, b */
   GdkColormap *colormap;
 
-  LOG ("Setup the page");
-
 #ifdef HAVE_LOCALE_H
   char *savelocale;
 #endif
 
+  LOG ("Setup the page");
+
   if (gs->pstarget == NULL)
     return;
 
@@ -720,8 +720,6 @@
   int std_out[2];               /* pipe from interp stdout */
   int std_err[2];               /* pipe from interp stderr */
 
-  LOG ("Start the interpreter");
-
 #define NUM_ARGS    100
 #define NUM_GS_ARGS (NUM_ARGS - 20)
 #define NUM_ALPHA_ARGS 10
@@ -729,6 +727,8 @@
   char *argv[NUM_ARGS], *dir, *gv_env;
   char **gs_args, **alpha_args = NULL;
   int argc = 0, i;
+
+  LOG ("Start the interpreter");
 
   if(!gs->gs_filename)
     return 0;
