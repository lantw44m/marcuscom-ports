--- gcalctool/ce_parser.h.orig	Mon Jul 26 22:11:59 2004
+++ gcalctool/ce_parser.h	Mon Jul 26 22:12:20 2004
@@ -48,11 +48,12 @@
 static inline char *
 ce_strndup(char *str, int len)
 {
+    char *dup;
     if (len < 1) {
         return(NULL); 
     }
 
-    char *dup = malloc(len+1);
+    dup = malloc(len+1);
     memset(dup, 0, len+1);
     strncpy(dup, str, len);
 
