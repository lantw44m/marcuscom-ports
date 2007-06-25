--- library/gnome-keyring-memory.c.orig	2007-06-25 13:42:22.000000000 -0400
+++ library/gnome-keyring-memory.c	2007-06-25 13:42:38.000000000 -0400
@@ -219,7 +219,7 @@ gnome_keyring_memory_free (gpointer p)
 		return;
 	else if (!gkr_secure_memory_check (p))
 		g_free (p);
-		
+	else
 	gkr_secure_memory_free (p);
 }
 
