--- daemon/gnome-vfs-async-daemon.c.orig	Thu Oct 23 16:17:06 2003
+++ daemon/gnome-vfs-async-daemon.c	Thu Oct 23 16:19:26 2003
@@ -23,23 +23,23 @@
  *  the context object that has been looked up */
 G_LOCK_DEFINE_STATIC (client_call_context);
 
-static GnomeVFSAsyncDaemon *async_daemon = NULL;
+static GnomeVFSAsyncDaemon *g_vfs_async_daemon = NULL;
 
 static void
 gnome_vfs_async_daemon_finalize (GObject *object)
 {
 	/* All client calls should have finished before we kill this object */
-	g_assert (g_hash_table_size (async_daemon->client_call_context) == 0);
-	g_hash_table_destroy (async_daemon->client_call_context);
+	g_assert (g_hash_table_size (g_vfs_async_daemon->client_call_context) == 0);
+	g_hash_table_destroy (g_vfs_async_daemon->client_call_context);
 	BONOBO_CALL_PARENT (G_OBJECT_CLASS, finalize, (object));
-	async_daemon = NULL;
+	g_vfs_async_daemon = NULL;
 }
 
 static void
 gnome_vfs_async_daemon_instance_init (GnomeVFSAsyncDaemon *daemon)
 {
 	daemon->client_call_context = g_hash_table_new (NULL, NULL);
-	async_daemon = daemon;
+	g_vfs_async_daemon = daemon;
 }
 
 GnomeVFSContext *
@@ -48,13 +48,13 @@
 {
 	GnomeVFSContext *context;
 
-	if (async_daemon == NULL) {
+	if (g_vfs_async_daemon == NULL) {
 		return NULL;
 	}
 	
 	context = gnome_vfs_context_new ();
 	G_LOCK (client_call_context);
-	g_hash_table_insert (async_daemon->client_call_context, client_call, context);
+	g_hash_table_insert (g_vfs_async_daemon->client_call_context, client_call, context);
 	G_UNLOCK (client_call_context);
 
 	gnome_vfs_daemon_add_context (client, context);
@@ -72,8 +72,8 @@
 		_gnome_vfs_daemon_set_current_daemon_client_call (NULL);
 		gnome_vfs_daemon_remove_context (client, context);
 		G_LOCK (client_call_context);
-		if (async_daemon != NULL) {
-			g_hash_table_remove (async_daemon->client_call_context, client_call);
+		if (g_vfs_async_daemon != NULL) {
+			g_hash_table_remove (g_vfs_async_daemon->client_call_context, client_call);
 		}
 		gnome_vfs_context_free (context);
 		G_UNLOCK (client_call_context);
@@ -176,7 +176,7 @@
 	client_call = data;
 
 	G_LOCK (client_call_context);
-	context = g_hash_table_lookup (async_daemon->client_call_context, client_call);
+	context = g_hash_table_lookup (g_vfs_async_daemon->client_call_context, client_call);
 	if (context != NULL) {
 		cancellation = gnome_vfs_context_get_cancellation (context);
 		if (cancellation) {
