
$FreeBSD: ports/x11-toolkits/eel2/files/patch-eel::eel-vfs-extensions.c,v 1.2 2002/05/20 17:47:26 sobomax Exp $

--- eel/eel-vfs-extensions.c	2001/12/20 13:41:21	1.1
+++ eel/eel-vfs-extensions.c	2001/12/20 13:47:36
@@ -116,7 +116,8 @@
 
 	/* Return the file. */
 	*file_size = total_bytes_read;
-	*file_contents = g_realloc (buffer, total_bytes_read);
+	*file_contents = g_realloc (buffer, total_bytes_read + 1);
+	(*file_contents)[total_bytes_read] = '\0';
 	return GNOME_VFS_OK;
 }
 
