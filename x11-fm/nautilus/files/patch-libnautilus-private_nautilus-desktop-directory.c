--- libnautilus-private/nautilus-desktop-directory.c.orig	Mon Aug  4 01:14:37 2003
+++ libnautilus-private/nautilus-desktop-directory.c	Mon Aug  4 01:14:54 2003
@@ -409,10 +409,10 @@
 	desktop = NAUTILUS_DESKTOP_DIRECTORY (object);
 
 	nautilus_directory_unref (desktop->details->real_directory);
-	g_free (desktop->details);
 
 	g_hash_table_destroy (desktop->details->callbacks);
 	g_hash_table_destroy (desktop->details->monitors);
+	g_free (desktop->details);
 	
 	G_OBJECT_CLASS (parent_class)->finalize (object);
 }
