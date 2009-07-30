--- modules/os/seed-os.c.orig	2009-07-08 14:21:59.000000000 -0400
+++ modules/os/seed-os.c	2009-07-27 12:55:03.000000000 -0400
@@ -12,6 +12,9 @@
 #include <sys/utsname.h>
 
 #include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 
 #include <fcntl.h>
 
@@ -661,6 +664,7 @@ seed_os_fdatasync (SeedContext ctx,
 		   const SeedValue arguments[],
 		   SeedException * exception)
 {
+#if !defined(__FreeBSD__)
   gint fd;
 
   if (argument_count != 1)
@@ -670,6 +674,10 @@ seed_os_fdatasync (SeedContext ctx,
   fd = seed_value_to_int (ctx, arguments[0], exception);
 
   return seed_value_from_int (ctx, fdatasync (fd), exception);
+#else
+  errno = ENOSYS;
+  return seed_value_from_int (ctx, -1, exception);
+#endif
 }
 
 SeedValue
@@ -1070,7 +1078,9 @@ seed_module_init(SeedEngine * eng)
 #if defined (O_DIRECT)
   OS_DEFINE_QUICK_ENUM (O_DIRECT);
 #endif
+#if defined (O_DIRECTORY)
   OS_DEFINE_QUICK_ENUM (O_DIRECTORY);
+#endif
   OS_DEFINE_QUICK_ENUM (O_NOFOLLOW);
 #if defined (O_NOATIME)
   OS_DEFINE_QUICK_ENUM (O_NOATIME);
