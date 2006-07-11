--- modules/file-method-acl.c.orig	Tue Jun 13 16:04:46 2006
+++ modules/file-method-acl.c	Tue Jul 11 09:36:57 2006
@@ -45,7 +45,7 @@
 #endif
 
 #ifdef HAVE_POSIX_ACL
-# include <acl/libacl.h>
+# include <sys/acl.h>
 #define HAVE_ACL
 #endif
 
