--- glom/main.cc.orig	2008-08-08 02:55:08.000000000 +0200
+++ glom/main.cc	2008-08-08 02:55:59.000000000 +0200
@@ -84,14 +84,14 @@ OptionGroup::OptionGroup()
 
 } //namespace Glom
 
-extern "C" void __libc_freeres(void);
+//extern "C" void __libc_freeres(void);
 
 int 
 main(int argc, char* argv[])
 {
   //Force some cleanup at exit,
   //to help valgrind to detect memory leaks:
-  atexit(__libc_freeres);
+  //atexit(__libc_freeres);
 
   // TODO: I am not sure why, but this does not work. PYTHONPATH is set
   // correctly according to getenv(), but python still does not look in it.
