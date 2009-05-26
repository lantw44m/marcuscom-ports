--- src/calctool.c.orig	2009-05-24 22:47:31.000000000 +0200
+++ src/calctool.c	2009-05-26 18:30:34.000000000 +0200
@@ -64,7 +64,7 @@ matherr(struct exception *exc)
     
     /* Translators: Error displayed to user when the math library reports an
      * error */
-    snprintf(text, MAXLINE, _("Error in math library function %s"), exc->name);
+    snprintf(text, MAXLINE, _("Error in math library function %s"));
     doerr(text);
 
     return 1;
