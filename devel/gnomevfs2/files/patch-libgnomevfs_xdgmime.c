--- libgnomevfs/xdgmime.c.orig	Wed Jan  7 13:44:02 2004
+++ libgnomevfs/xdgmime.c	Tue Jan 13 01:55:41 2004
@@ -97,7 +97,7 @@
 
       xdg_data_dirs = getenv ("XDG_DATA_DIRS");
       if (xdg_data_dirs == NULL)
-	xdg_data_dirs = "/usr/local/share/:/usr/share/";
+	xdg_data_dirs = "%%LOCALBASE%%/share/:/usr/share/";
 
       ptr = xdg_data_dirs;
 
@@ -121,8 +121,9 @@
 	    len = end_ptr - ptr;
 	  else
 	    len = end_ptr - ptr + 1;
-	  dir = malloc (len);
+	  dir = malloc (len + 1);
 	  strncpy (dir, ptr, len);
+	  dir[len] = '\0';
 	  _xdg_mime_init_from_directory (dir);
 	  free (dir);
 
