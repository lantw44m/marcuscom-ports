--- src/ck-vt-monitor.c.orig	2008-01-23 09:30:44.000000000 -0500
+++ src/ck-vt-monitor.c	2008-01-23 15:29:52.000000000 -0500
@@ -54,6 +54,9 @@ struct CkVtMonitorPrivate
 
         GAsyncQueue     *event_queue;
         guint            process_queue_id;
+
+        GAsyncQueue     *restart_queue;
+        guint            restart_queue_id;
 };
 
 enum {
@@ -72,6 +75,7 @@ static void     ck_vt_monitor_init      
 static void     ck_vt_monitor_finalize    (GObject          *object);
 
 static void     vt_add_watches            (CkVtMonitor      *vt_monitor);
+static void     vt_add_watch_unlocked     (CkVtMonitor      *vt_monitor, gint32 num);
 
 G_DEFINE_TYPE (CkVtMonitor, ck_vt_monitor, G_TYPE_OBJECT)
 
@@ -254,6 +258,56 @@ process_queue (CkVtMonitor *vt_monitor)
         return FALSE;
 }
 
+static gboolean
+process_restart_queue (CkVtMonitor *vt_monitor)
+{
+        int        i;
+        int        queue_length;
+        EventData *data;
+        EventData *d;
+
+        g_async_queue_lock (vt_monitor->priv->restart_queue);
+
+        g_debug ("Processing VT restart queue");
+
+        queue_length = g_async_queue_length_unlocked (vt_monitor->priv->restart_queue);
+        data = NULL;
+
+        G_LOCK (hash_lock);
+
+        /* compress events in the queue */
+        for (i = 0; i < queue_length; i++) {
+                d = g_async_queue_try_pop_unlocked (vt_monitor->priv->restart_queue);
+                if (d == NULL) {
+                        continue;
+
+                }
+
+                if (data != NULL) {
+                        g_debug ("Compressing queue; skipping restart for VT %d", data->num);
+                        event_data_free (data);
+                }
+
+                data = d;
+        }
+
+        if (data != NULL) {
+                vt_add_watch_unlocked (vt_monitor, data->num);
+                event_data_free (data);
+        }
+
+        G_UNLOCK (hash_lock);
+
+        G_LOCK (schedule_lock);
+        vt_monitor->priv->restart_queue_id = 0;
+        G_UNLOCK (schedule_lock);
+
+        g_async_queue_unlock (vt_monitor->priv->restart_queue);
+
+        return FALSE;
+}
+
+
 static void
 schedule_process_queue (CkVtMonitor *vt_monitor)
 {
@@ -264,6 +318,16 @@ schedule_process_queue (CkVtMonitor *vt_
         G_UNLOCK (schedule_lock);
 }
 
+static void
+schedule_process_restart_queue (CkVtMonitor *vt_monitor)
+{
+        G_LOCK (schedule_lock);
+        if (vt_monitor->priv->restart_queue_id == 0) {
+                vt_monitor->priv->restart_queue_id = g_idle_add ((GSourceFunc)process_restart_queue, vt_monitor);
+        }
+        G_UNLOCK (schedule_lock);
+}
+
 static void *
 vt_thread_start (ThreadData *data)
 {
@@ -277,7 +341,15 @@ vt_thread_start (ThreadData *data)
 
         res = ck_wait_for_active_console_num (vt_monitor->priv->vfd, num);
         if (! res) {
-                /* FIXME: what do we do if it fails? */
+                EventData *event;
+
+                event = g_new0 (EventData, 1);
+                event->num = num;
+                g_debug ("Failed to wait for active console %d: %s", num, g_strerror (errno));
+
+                g_async_queue_push (vt_monitor->priv->restart_queue, event);
+
+                schedule_process_restart_queue (vt_monitor);
         } else {
                 EventData *event;
 
@@ -414,6 +486,7 @@ ck_vt_monitor_init (CkVtMonitor *vt_moni
 
                 vt_monitor->priv->active_num = active;
                 vt_monitor->priv->event_queue = g_async_queue_new ();
+                vt_monitor->priv->restart_queue = g_async_queue_new ();
                 vt_monitor->priv->vt_thread_hash = g_hash_table_new (g_direct_hash, g_direct_equal);
 
                 vt_add_watches (vt_monitor);
@@ -440,6 +513,10 @@ ck_vt_monitor_finalize (GObject *object)
                 g_async_queue_unref (vt_monitor->priv->event_queue);
         }
 
+        if (vt_monitor->priv->restart_queue != NULL) {
+                g_async_queue_unref (vt_monitor->priv->restart_queue);
+        }
+
         if (vt_monitor->priv->vt_thread_hash != NULL) {
                 g_hash_table_destroy (vt_monitor->priv->vt_thread_hash);
         }
