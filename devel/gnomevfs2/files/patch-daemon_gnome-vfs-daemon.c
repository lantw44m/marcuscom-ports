--- daemon/gnome-vfs-daemon.c.orig	Mon Nov 10 18:17:52 2003
+++ daemon/gnome-vfs-daemon.c	Mon Nov 10 18:18:30 2003
@@ -14,7 +14,7 @@
 
 /* Global daemon */
 static GnomeVFSDaemon *the_daemon = NULL;
-static GnomeVFSAsyncDaemon *async_daemon = NULL;
+static GnomeVFSAsyncDaemon *gnomevfs_async_daemon = NULL;
 
 typedef struct {
 	GNOME_VFS_Client client;
@@ -534,12 +534,12 @@
 		the_daemon = g_object_new (GNOME_TYPE_VFS_DAEMON, NULL);
 
 		poa = bonobo_poa_get_threaded (ORBIT_THREAD_HINT_PER_REQUEST);
-		async_daemon = g_object_new (GNOME_TYPE_VFS_ASYNC_DAEMON,
+		gnomevfs_async_daemon = g_object_new (GNOME_TYPE_VFS_ASYNC_DAEMON,
 					     "poa", poa,
 					     NULL);
 		CORBA_Object_release ((CORBA_Object)poa, NULL);
 		bonobo_object_add_interface (BONOBO_OBJECT (the_daemon),
-					     BONOBO_OBJECT (async_daemon));
+					     BONOBO_OBJECT (gnomevfs_async_daemon));
 	}
 	return BONOBO_OBJECT (the_daemon);
 }
