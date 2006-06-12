--- modules/file-method-acl.c.orig	Mon Jun 12 14:12:40 2006
+++ modules/file-method-acl.c	Mon Jun 12 14:12:52 2006
@@ -45,7 +45,7 @@
 #endif
 
 #ifdef HAVE_POSIX_ACL
-# include <acl/libacl.h>
+# include <sys/acl.h>
 #endif
 
 #ifdef HAVE_SOLARIS_ACL
