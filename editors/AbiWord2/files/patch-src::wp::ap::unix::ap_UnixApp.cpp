
$FreeBSD$

--- src/wp/ap/unix/ap_UnixApp.cpp.orig	Thu Jun 17 14:57:19 2004
+++ src/wp/ap/unix/ap_UnixApp.cpp	Thu Jun 17 14:58:01 2004
@@ -788,7 +788,7 @@
   {
       pluginDir = pluginList[i];
 
-      n = scandir(pluginDir.c_str(), &namelist, so_only, alphasort);
+      n = scandir(pluginDir.c_str(), &namelist, (int (*)(dirent *))so_only, alphasort);
       UT_DEBUGMSG(("DOM: found %d plugins in %s\n", n, pluginDir.c_str()));
 
       if (n > 0)

