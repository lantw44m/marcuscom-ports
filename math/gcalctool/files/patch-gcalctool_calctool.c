--- gcalctool/calctool.c.orig	2009-05-04 02:10:30.000000000 +0200
+++ gcalctool/calctool.c	2009-05-06 16:14:25.000000000 +0200
@@ -115,7 +115,7 @@ matherr(struct exception *exc)
     
     /* Translators: Error displayed to user when the math library reports an
      * error */
-    snprintf(text, MAXLINE, _("Error in math library function %s"), exc->name);
+    snprintf(text, MAXLINE, _("Error in math library function %s"));
     doerr(text);
 
     return 1;
