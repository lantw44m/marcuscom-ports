$FreeBSD$
  $MCom: ports/www/firefox/files/patch-config-mkdepend-imakemdep.h,v 1.5 2005/06/28 05:40:11 adamw Exp $

--- config/mkdepend/imakemdep.h	Fri Sep  4 21:22:25 1998
+++ config/mkdepend/imakemdep.h	Thu Oct 16 22:43:25 2003
@@ -278,4 +278,7 @@
 	"-D__i386__",
 # endif
+# if defined(__amd64__) || defined(__x86_64__)
+	"-D__amd64__ -D__x86_64__",
+# endif
 # ifdef __GNUC__
 	"-traditional",
