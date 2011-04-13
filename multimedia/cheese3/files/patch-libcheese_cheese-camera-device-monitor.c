--- libcheese/cheese-camera-device-monitor.c.orig	2011-03-07 21:08:19.000000000 +0100
+++ libcheese/cheese-camera-device-monitor.c	2011-04-13 11:07:36.000000000 +0200
@@ -30,16 +30,11 @@
   #define G_UDEV_API_IS_SUBJECT_TO_CHANGE 1
   #include <gudev/gudev.h>
 #else
-  #include <fcntl.h>
-  #include <unistd.h>
-  #include <sys/ioctl.h>
-  #if USE_SYS_VIDEOIO_H > 0
-    #include <sys/types.h>
-    #include <sys/videoio.h>
-  #elif defined (__sun)
-    #include <sys/types.h>
-    #include <sys/videodev2.h>
-  #endif /* USE_SYS_VIDEOIO_H */
+ #include <glib/gstdio.h> 
+ #include <libhal.h>
+ #include <dbus/dbus.h>
+ #include <dbus/dbus-glib-lowlevel.h>
+ #include <unistd.h>
 #endif
 
 #include "cheese-camera-device-monitor.h"
@@ -82,6 +77,8 @@ typedef struct
 #ifdef HAVE_UDEV
   GUdevClient *client;
 #else
+  DBusConnection *connection;
+  LibHalContext *hal_ctx;
   guint filler;
 #endif /* HAVE_UDEV */
 } CheeseCameraDeviceMonitorPrivate;
@@ -243,93 +240,240 @@ cheese_camera_device_monitor_coldplug (C
   if (i == 0) GST_WARNING ("No device found");
 }
 
-#else /* HAVE_UDEV */
-void
-cheese_camera_device_monitor_coldplug (CheeseCameraDeviceMonitor *monitor)
+static void
+cheese_camera_device_monitor_finalize (GObject *object)
 {
-  #if 0
+  CheeseCameraDeviceMonitor *monitor;
+
+  monitor = CHEESE_CAMERA_DEVICE_MONITOR (object);
   CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
-  struct v4l2_capability            v2cap;
-  struct video_capability           v1cap;
-  int                               fd, ok;
 
-  if ((fd = open (device_path, O_RDONLY | O_NONBLOCK)) < 0)
+  if (priv->client != NULL)
   {
-    g_warning ("Failed to open %s: %s", device_path, strerror (errno));
+    g_object_unref (priv->client);
+    priv->client = NULL;
+  }
+  G_OBJECT_CLASS (cheese_camera_device_monitor_parent_class)->finalize (object);
+}
+
+static void
+cheese_camera_device_monitor_class_init (CheeseCameraDeviceMonitorClass *klass)
+{  
+  GObjectClass *object_class = G_OBJECT_CLASS (klass);
+
+  if (cheese_device_monitor_cat == NULL)
+    GST_DEBUG_CATEGORY_INIT (cheese_device_monitor_cat,
+                             "cheese-device-monitor",
+                             0, "Cheese Camera Device Monitor");
+   
+  object_class->finalize = cheese_camera_device_monitor_finalize;
+  
+  /**
+   * CheeseCameraDeviceMonitor::added:
+   * @device: A private object representing the newly added camera.
+   * @id: Device unique identifier.
+   * @device: Device file name  (e.g. /dev/video2).
+   * @product_name: Device product name (human readable, intended to be displayed in a UI).
+   * @api_version: Supported video4linux API: 1 for v4l, 2 for v4l2.
+   *
+   * The ::added signal is emitted when a camera is added, or on start-up
+   * after #cheese_camera_device_monitor_colplug is called.
+   **/
+  monitor_signals[ADDED] = g_signal_new ("added", G_OBJECT_CLASS_TYPE (klass),
+                                         G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
+                                         G_STRUCT_OFFSET (CheeseCameraDeviceMonitorClass, added),
+                                         NULL, NULL,
+                                         _cheese_marshal_VOID__STRING_STRING_STRING_INT,
+                                         G_TYPE_NONE, 4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
+
+  /**
+   * CheeseCameraDeviceMonitor::removed:
+   * @device: A private object representing the newly added camera
+   * @id: Device unique identifier.
+   *
+   * The ::removed signal is emitted when a camera is un-plugged, or
+   * disabled on the system.
+   **/
+  monitor_signals[REMOVED] = g_signal_new ("removed", G_OBJECT_CLASS_TYPE (klass),
+                                           G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
+                                           G_STRUCT_OFFSET (CheeseCameraDeviceMonitorClass, removed),
+                                           NULL, NULL,
+                                           g_cclosure_marshal_VOID__STRING,
+                                           G_TYPE_NONE, 1, G_TYPE_STRING);
+
+  g_type_class_add_private (klass, sizeof (CheeseCameraDeviceMonitorPrivate));
+}
+
+static void
+cheese_camera_device_monitor_init (CheeseCameraDeviceMonitor *monitor)
+{
+  CheeseCameraDeviceMonitorPrivate *priv         = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
+  const gchar *const                subsystems[] = {"video4linux", NULL};
+
+  priv->client = g_udev_client_new (subsystems);
+  g_signal_connect (G_OBJECT (priv->client), "uevent",
+                    G_CALLBACK (cheese_camera_device_monitor_uevent_cb), monitor);
+}
+
+#else /* HAVE_UDEV */
+
+static void
+cheese_camera_device_monitor_handle_udi (CheeseCameraDeviceMonitor *monitor,
+                                         const char                *udi)
+ {
+  CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
+  char               *device_file;
+  char               *product_name;
+  char               *capstr;
+  gint                v4l_version = 0;
+  DBusError           error;
+
+  GST_INFO ("Checking hal device '%s'", udi);
+
+  dbus_error_init (&error);
+
+  product_name = libhal_device_get_property_string (priv->hal_ctx, udi, "info.product", &error);
+  if (dbus_error_is_set (&error))
+  {
+    GST_WARNING ("error getting product name: %s: %s", error.name, error.message);
+    dbus_error_free (&error);
     return;
   }
-  ok = ioctl (fd, VIDIOC_QUERYCAP, &v2cap);
-  if (ok < 0)
+
+  device_file = libhal_device_get_property_string (priv->hal_ctx, udi, "video4linux.device", &error);
+  if (dbus_error_is_set (&error))
   {
-    ok = ioctl (fd, VIDIOCGCAP, &v1cap);
-    if (ok < 0)
-    {
-      g_warning ("Error while probing v4l capabilities for %s: %s",
-                 device_path, strerror (errno));
-      close (fd);
-      return;
-    }
-    g_print ("Detected v4l device: %s\n", v1cap.name);
-    g_print ("Device type: %d\n", v1cap.type);
-    gstreamer_src = "v4lsrc";
-    product_name  = v1cap.name;
+    GST_WARNING ("error getting V4L device for %s: %s: %s", udi, error.name, error.message);
+    dbus_error_free (&error);
+    libhal_free_string (product_name);
   }
-  else
+
+  if (g_access (device_file, (R_OK | W_OK)) == -1)
   {
-    guint cap = v2cap.capabilities;
-    g_print ("Detected v4l2 device: %s\n", v2cap.card);
-    g_print ("Driver: %s, version: %d\n", v2cap.driver, v2cap.version);
-
-    /* g_print ("Bus info: %s\n", v2cap.bus_info); */ /* Doesn't seem anything useful */
-    g_print ("Capabilities: 0x%08X\n", v2cap.capabilities);
-    if (!(cap & V4L2_CAP_VIDEO_CAPTURE))
-    {
-      g_print ("Device %s seems to not have the capture capability, (radio tuner?)\n"
-               "Removing it from device list.\n", device_path);
-      close (fd);
-      return;
-    }
-    gstreamer_src = "v4l2src";
-    product_name  = (char *) v2cap.card;
+    GST_WARNING ("Device %s does not have proper permissions.  Permissions must be 0666", device_file);
+    libhal_free_string (product_name);
+    libhal_free_string (device_file);
+    return;
   }
-  close (fd);
 
-  GList *devices, *l;
+  capstr = libhal_device_get_property_string (priv->hal_ctx, udi, "video4linux.version", &error);
+  if (dbus_error_is_set (&error))
+  {
+    GST_WARNING ("error getting V4L version for %s: %s: %s", udi, error.name, error.message);
+    dbus_error_free (&error);
+    libhal_free_string (product_name);
+    libhal_free_string (device_file);
+    return;
+  }
 
-  g_print ("Probing devices with udev...\n");
+  v4l_version = atoi (capstr);
+  libhal_free_string (capstr);
 
-  if (priv->client == NULL)
-    return;
+   g_signal_emit (monitor, monitor_signals[ADDED], 0,
+                  udi,
+                  device_file,
+                  product_name,
+                  v4l_version);
+}
 
-  devices = g_udev_client_query_by_subsystem (priv->client, "video4linux");
+static void
+cheese_camera_device_monitor_removed (LibHalContext             *ctx,
+                                      const char                *udi)
+ {
+  CheeseCameraDeviceMonitor *monitor;
+  void *data;
 
-  /* Initialize camera structures */
-  for (l = devices; l != NULL; l = l->next)
+  data = libhal_ctx_get_user_data (ctx);
+  g_assert (data);
+
+  monitor = CHEESE_CAMERA_DEVICE_MONITOR (data);
+
+  g_signal_emit (monitor, monitor_signals[REMOVED], 0, udi);
+}
+
+void
+cheese_camera_device_monitor_coldplug (CheeseCameraDeviceMonitor *monitor)
+{
+  CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
+  gint i, num_udis = 0;
+  gchar **udis;
+  DBusError error;
+
+  if (priv->hal_ctx == NULL)
+     return;
+
+  GST_INFO ("Probing devices with HAL...");  
+
+  dbus_error_init (&error);
+
+  udis = libhal_find_device_by_capability (priv->hal_ctx, "video4linux", &num_udis, &error);
+
+  if (dbus_error_is_set (&error))
   {
-    cheese_camera_device_monitor_added (monitor, l->data);
-    g_object_unref (l->data);
+    GST_WARNING ("libhal_find_device_by_capability: %s: %s", error.name, error.message);
+    dbus_error_free (&error);
+    return;
   }
-  g_list_free (devices);
-  #endif
+
+  /* Initialize camera structures */
+  for (i = 0; i < num_udis; i++)
+    cheese_camera_device_monitor_handle_udi (monitor, udis[i]);
+  libhal_free_string_array (udis);
+
+  if (i == 0) 
+    GST_WARNING ("No device found");
 }
 
-#endif /* HAVE_UDEV */
+static void
+cheese_camera_device_monitor_added (LibHalContext *ctx, const char *udi)
+{
+  CheeseCameraDeviceMonitor *monitor;
+  gchar **caps;
+  guint i;
+  void *data;
+
+  data = libhal_ctx_get_user_data (ctx);
+  g_assert (data);
+
+  monitor = CHEESE_CAMERA_DEVICE_MONITOR (data);
+
+  caps = libhal_device_get_property_strlist (ctx, udi, "info.capabilities", NULL);
+  if (caps == NULL)
+    return;
+
+  for (i = 0; caps[i] != NULL; i++)
+  {
+    if (g_strcmp0 (caps[i], "video4linux") == 0)
+    {
+      cheese_camera_device_monitor_handle_udi (monitor, udi);
+      break;
+    }
+  }
+  libhal_free_string_array (caps);
+}
 
 static void
 cheese_camera_device_monitor_finalize (GObject *object)
 {
-#ifdef HAVE_UDEV
   CheeseCameraDeviceMonitor *monitor;
 
   monitor = CHEESE_CAMERA_DEVICE_MONITOR (object);
   CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
 
-  if (priv->client != NULL)
+  if (priv->connection != NULL)
   {
-    g_object_unref (priv->client);
-    priv->client = NULL;
+    dbus_connection_unref (priv->connection);
+    priv->connection = NULL;
   }
-#endif /* HAVE_UDEV */
+
+  if (priv->hal_ctx != NULL)
+  {
+    libhal_ctx_set_device_added (priv->hal_ctx, NULL);
+    libhal_ctx_set_device_removed (priv->hal_ctx, NULL);
+    libhal_ctx_free (priv->hal_ctx);
+    priv->hal_ctx = NULL;
+  }
+
   G_OBJECT_CLASS (cheese_camera_device_monitor_parent_class)->finalize (object);
 }
 
@@ -384,16 +528,56 @@ cheese_camera_device_monitor_class_init 
 static void
 cheese_camera_device_monitor_init (CheeseCameraDeviceMonitor *monitor)
 {
-#ifdef HAVE_UDEV
-  CheeseCameraDeviceMonitorPrivate *priv         = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
-  const gchar *const                subsystems[] = {"video4linux", NULL};
+  CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
+  LibHalContext *hal_ctx;
+  DBusError      error;
 
-  priv->client = g_udev_client_new (subsystems);
-  g_signal_connect (G_OBJECT (priv->client), "uevent",
-                    G_CALLBACK (cheese_camera_device_monitor_uevent_cb), monitor);
-#endif /* HAVE_UDEV */
+  dbus_error_init (&error);
+
+  priv->connection = dbus_bus_get (DBUS_BUS_SYSTEM, &error);
+
+  dbus_connection_set_exit_on_disconnect (priv->connection, FALSE);
+
+  hal_ctx = libhal_ctx_new ();
+  if (hal_ctx == NULL)
+  {
+    GST_WARNING ("Could not create libhal context");
+    dbus_error_free (&error);
+    return;
+  }
+
+  if (!libhal_ctx_set_dbus_connection (hal_ctx, priv->connection))
+  {
+    GST_WARNING ("libhal_ctx_set_dbus_connection: %s: %s", error.name, error.message);
+    dbus_error_free (&error);
+    return;
+  }
+  if (!libhal_ctx_init (hal_ctx, &error))
+  {
+    if (dbus_error_is_set (&error))
+    {
+      GST_WARNING ("libhal_ctx_init: %s: %s", error.name, error.message);
+      dbus_error_free (&error);
+    }
+    GST_WARNING ("Could not initialise connection to hald.\n"
+                "Normally this means the HAL daemon (hald) is not running or not ready");
+    return;
+  }
+
+  dbus_connection_setup_with_g_main (priv->connection, NULL);
+
+  if (!libhal_ctx_set_user_data (hal_ctx, monitor))
+    GST_WARNING ("Failed to set user data on HAL context");
+  if (!libhal_ctx_set_device_added (hal_ctx, cheese_camera_device_monitor_added))
+    GST_WARNING ("Failed to connect to device added signal from HAL");
+  if (!libhal_ctx_set_device_removed (hal_ctx, cheese_camera_device_monitor_removed))
+    GST_WARNING ("Failed to connect to device removed signal from HAL");
+
+  priv->hal_ctx = hal_ctx;
 }
 
+#endif /* !HAVE_UDEV */
+
 /**
  * cheese_camera_device_monitor_new:
  *
