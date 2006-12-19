--- libltdl/acinclude.m4.orig	Sun Dec 17 13:11:01 2006
+++ libltdl/acinclude.m4	Sun Dec 17 13:11:14 2006
@@ -6524,6 +6524,9 @@
     # If you are looking for one http://www.opendarwin.org/projects/dlcompat
     libltdl_cv_sys_dlopen_deplibs=yes
     ;;
+  freebsd*)
+    libltdl_cv_sys_dlopen_deplibs=yes
+    ;;
   gnu* | linux* | kfreebsd*-gnu | knetbsd*-gnu)
     # GNU and its variants, using gnu ld.so (Glibc)
     libltdl_cv_sys_dlopen_deplibs=yes
