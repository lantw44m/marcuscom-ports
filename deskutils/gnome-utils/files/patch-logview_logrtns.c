--- logview/logrtns.c.orig	Sun Feb 20 13:03:24 2005
+++ logview/logrtns.c	Sun Feb 20 13:27:46 2005
@@ -217,6 +217,10 @@ OpenLogFile (char *filename)
 	   return NULL;
    }
 
+   /* gnome_vfs_read_entire_file() does not return a NUL-terminated buffer. */
+   buffer = g_realloc (buffer, size+1);
+   buffer[size] = '\0';
+
    /* Alloc memory for log structure */
    tlog = g_new0 (Log, 1);
    if (tlog == NULL) {
@@ -230,6 +234,7 @@ OpenLogFile (char *filename)
 	   g_free (filename);
 
    buffer_lines = g_strsplit (buffer, "\n", -1);
+   g_free (buffer);
 
    /* count the lines */
    for (i=0; buffer_lines[i+1] != NULL; i++);
