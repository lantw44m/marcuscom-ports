--- libgnomevfs/xdgmime.c.orig	Thu Jul 22 11:20:13 2004
+++ libgnomevfs/xdgmime.c	Thu Jul 22 11:20:52 2004
@@ -189,7 +189,7 @@
 
   xdg_data_dirs = getenv ("XDG_DATA_DIRS");
   if (xdg_data_dirs == NULL)
-    xdg_data_dirs = "/usr/local/share/:/usr/share/";
+    xdg_data_dirs = "/usr/local/share/:%%X11BASE%%/share/:/usr/share/:/usr/local/share/gnome:%%X11BASE%%/share/gnome/:/usr/share/gnome/";
 
   ptr = xdg_data_dirs;
 
