--- src/encoding.c.orig	Fri Jan 10 13:28:26 2003
+++ src/encoding.c	Fri Jan 10 13:28:35 2003
@@ -352,8 +352,8 @@
   for (tmp = strings; tmp != NULL; tmp = tmp->next)
     {
       const TerminalEncoding *e;
-      charset = tmp->data;
       TerminalEncoding *encoding;
+      charset = tmp->data;
       
       if (strcmp (charset, "current") == 0)
         g_get_charset (&charset);
