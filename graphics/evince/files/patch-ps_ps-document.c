--- ps/ps-document.c.orig	Mon Feb 28 16:53:42 2005
+++ ps/ps-document.c	Thu Mar  3 04:09:09 2005
@@ -548,11 +548,10 @@
   GdkColormap *colormap;
   gboolean size_changed;
 
-  LOG ("Setup the page");
-
 #ifdef HAVE_LOCALE_H
   char *savelocale;
 #endif
+  LOG ("Setup the page");
 
   size_changed = compute_size (gs);
 
@@ -783,8 +782,6 @@
   int std_out[2];               /* pipe from interp stdout */
   int std_err[2];               /* pipe from interp stderr */
 
-  LOG ("Start the interpreter");
-
 #define NUM_ARGS    100
 #define NUM_GS_ARGS (NUM_ARGS - 20)
 #define NUM_ALPHA_ARGS 10
@@ -792,6 +789,8 @@
   char *argv[NUM_ARGS], *dir, *gv_env;
   char **gs_args, **alpha_args = NULL;
   int argc = 0, i;
+
+  LOG ("Start the interpreter");
 
   if(!gs->gs_filename)
     return 0;
