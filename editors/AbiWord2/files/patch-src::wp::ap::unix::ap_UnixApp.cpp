
$FreeBSD: ports/editors/AbiWord2/files/patch-src::wp::ap::unix::ap_UnixApp.cpp,v 1.3 2003/02/23 18:39:36 marcus Exp $

--- src/wp/ap/unix/ap_UnixApp.cpp.orig	Thu Dec  6 09:00:14 2001
+++ src/wp/ap/unix/ap_UnixApp.cpp	Mon Dec 17 13:49:48 2001
@@ -612,7 +612,7 @@
   {
       pluginDir = pluginList[i];
 
-      n = scandir(pluginDir.c_str(), &namelist, so_only, alphasort);
+      n = scandir(pluginDir.c_str(), &namelist, (int (*)(dirent *))so_only, alphasort);
       UT_DEBUGMSG(("DOM: found %d plugins in %s\n", n, pluginDir.c_str()));
 
       if (n > 0)
