--- modules/os/seed-os.c.orig	2009-08-10 16:23:35.000000000 -0400
+++ modules/os/seed-os.c	2009-08-22 14:18:53.000000000 -0400
@@ -30,7 +30,11 @@
 #include <sys/stat.h>
 #include <sys/utsname.h>
 
+#include <sys/param.h>
 #include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
 
 #include <fcntl.h>
 
@@ -55,6 +59,7 @@ seed_os_realpath (SeedContext ctx,
 	          SeedException * exception)
 {
   gchar *arg;
+  gchar resolved_path[PATH_MAX];
   gchar *ret;
 
   if (argument_count != 1)
@@ -62,7 +67,7 @@ seed_os_realpath (SeedContext ctx,
       EXPECTED_EXCEPTION("os.realpath", "1 argument");
     }
   arg = seed_value_to_string (ctx, arguments[0], exception);
-  ret = canonicalize_file_name(arg);
+  ret = realpath(arg, resolved_path);
   g_free (arg);
 
   return seed_value_from_string (ctx, ret, exception);
@@ -702,6 +707,7 @@ seed_os_fdatasync (SeedContext ctx,
 		   const SeedValue arguments[],
 		   SeedException * exception)
 {
+#if !defined(__FreeBSD__)
   gint fd;
 
   if (argument_count != 1)
@@ -711,6 +717,10 @@ seed_os_fdatasync (SeedContext ctx,
   fd = seed_value_to_int (ctx, arguments[0], exception);
 
   return seed_value_from_int (ctx, fdatasync (fd), exception);
+#else
+  errno = ENOSYS;
+  return seed_value_from_int (ctx, -1, exception);
+#endif
 }
 
 SeedValue
@@ -1112,7 +1122,9 @@ seed_module_init(SeedEngine * eng)
 #if defined (O_DIRECT)
   OS_DEFINE_QUICK_ENUM (O_DIRECT);
 #endif
+#if defined (O_DIRECTORY)
   OS_DEFINE_QUICK_ENUM (O_DIRECTORY);
+#endif
   OS_DEFINE_QUICK_ENUM (O_NOFOLLOW);
 #if defined (O_NOATIME)
   OS_DEFINE_QUICK_ENUM (O_NOATIME);
