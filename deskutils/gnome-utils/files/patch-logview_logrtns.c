--- logview/logrtns.c.orig	Tue Nov 15 00:56:04 2005
+++ logview/logrtns.c	Tue Nov 15 00:56:56 2005
@@ -348,7 +348,7 @@ log_open (char *filename, gboolean show_
    Day *day;
    GError *error;
    GnomeVFSResult result;
-   ulong size;
+   gulong size;
    
    if (file_exist (filename, show_error) == FALSE)
 	   return NULL;
