--- libgnomevfs/xdgmime.c.orig	Tue Jan 13 01:20:05 2004
+++ libgnomevfs/xdgmime.c	Tue Jan 13 01:20:35 2004
@@ -97,7 +97,7 @@
 
       xdg_data_dirs = getenv ("XDG_DATA_DIRS");
       if (xdg_data_dirs == NULL)
-	xdg_data_dirs = "/usr/local/share/:/usr/share/";
+	xdg_data_dirs = "%%LOCALBASE%%/share/:/usr/share/";
 
       ptr = xdg_data_dirs;
 
@@ -121,7 +121,8 @@
 	    len = end_ptr - ptr;
 	  else
 	    len = end_ptr - ptr + 1;
-	  dir = malloc (len);
+	  dir = malloc (len + 1);
+	  memset (dir, 0, len + 1);
 	  strncpy (dir, ptr, len);
 	  _xdg_mime_init_from_directory (dir);
 	  free (dir);
