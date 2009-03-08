--- src/gs-idle-monitor.c.orig	2009-03-07 21:35:19.000000000 -0500
+++ src/gs-idle-monitor.c	2009-03-07 21:36:00.000000000 -0500
@@ -271,13 +271,6 @@ init_xsync (GSIdleMonitor *monitor)
                 return FALSE;
         }
 
-        /* select for sync events */
-        gdk_error_trap_push ();
-        XSelectInput (GDK_DISPLAY (), GDK_ROOT_WINDOW (), XSyncAlarmNotifyMask);
-        if (gdk_error_trap_pop ()) {
-                g_warning ("XSelectInput failed");
-        }
-
         gdk_window_add_filter (NULL, (GdkFilterFunc)xevent_filter, monitor);
 
         return TRUE;
@@ -438,13 +431,15 @@ _xsync_alarm_set (GSIdleMonitor      *mo
                 | XSyncCAValueType
                 | XSyncCATestType
                 | XSyncCAValue
-                | XSyncCADelta;
+                | XSyncCADelta
+		| XSyncCAEvents;
 
         XSyncIntToValue (&delta, 0);
         attr.trigger.counter = monitor->priv->counter;
         attr.trigger.value_type = XSyncAbsolute;
         attr.trigger.wait_value = watch->interval;
         attr.delta = delta;
+	attr.events = True;
 
         attr.trigger.test_type = XSyncPositiveTransition;
         if (watch->xalarm_positive != None) {
