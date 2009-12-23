--- hald/freebsd/hf-usb2.c.orig	2009-08-24 08:42:29.000000000 -0400
+++ hald/freebsd/hf-usb2.c	2009-12-23 14:16:03.000000000 -0500
@@ -98,10 +98,10 @@ hf_usb2_probe_interfaces(HalDevice *pare
 	  if (driver)
             {
 	      if (! strcmp(driver, "ukbd"))
-                hf_device_set_input(device, "keyboard", NULL);
-	      else if (! strcmp(driver, "ums"))
+                hf_device_set_input(device, "keyboard", "keys", devname);
+	      else if (! strcmp(driver, "ums") || ! strcmp(driver, "atp"))
                 {
-                  hf_device_set_input(device, "mouse", devname);
+                  hf_device_set_input(device, "mouse", NULL, devname);
 	          hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
 	        }
 	      else if (! strcmp(driver, "uhid"))
@@ -192,11 +192,12 @@ hf_usb2_probe (void)
       addr = libusb20_dev_get_address(pdev);
 
       if (addr == 1)
-        parent = hf_devtree_find_parent_from_info(hald_get_gdl(), "usbus", bus);
+        parent = hf_devtree_find_from_info(hald_get_gdl(), "usbus", bus);
       else
         parent = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
           HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
-	  HAL_PROPERTY_TYPE_INT32, addr - 1, NULL);
+	  HAL_PROPERTY_TYPE_INT32, addr - 1, "info.bus",
+	  HAL_PROPERTY_TYPE_STRING, "usb_device", NULL);
       if (! parent || hal_device_property_get_bool(parent, "info.ignore"))
         continue;
 
@@ -216,7 +217,13 @@ hf_usb2_devd_add (const char *name,
   HalDevice *parent_device;
   int bus, addr, pbus, paddr;
 
-  if (strncmp(name, "ugen", strlen("ugen")))
+  if (! parent)
+    return FALSE;
+
+  if (strncmp(name, "ugen", strlen("ugen")) &&
+      ! strncmp(parent, "uhub", strlen("uhub")))
+    return TRUE;
+  else if (strncmp(name, "ugen", strlen("ugen")))
     return FALSE;
   else if (strncmp(parent, "ugen", strlen("ugen")))
     return TRUE;
@@ -232,7 +239,8 @@ hf_usb2_devd_add (const char *name,
 
   parent_device = hf_device_store_match(hald_get_gdl(),
     "usb_device.bus_number", HAL_PROPERTY_TYPE_INT32, pbus,
-    "usb_device.port_number", HAL_PROPERTY_TYPE_INT32, paddr, NULL);
+    "usb_device.port_number", HAL_PROPERTY_TYPE_INT32, paddr, "info.bus",
+    HAL_PROPERTY_TYPE_STRING, "usb_device", NULL);
 
   if (parent_device && ! hal_device_property_get_bool(parent_device,
       "info.ignore"))
@@ -255,8 +263,6 @@ hf_usb2_devd_remove (const char *name,
 
   if (strncmp(name, "ugen", strlen("ugen")))
     return FALSE;
-  else if (strncmp(parent, "ugen", strlen("ugen")))
-    return TRUE;
 
   if (sscanf(name, "ugen%i.%i", &bus, &addr) != 2)
     return FALSE;
@@ -265,7 +271,8 @@ hf_usb2_devd_remove (const char *name,
 
   device = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
     HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
-    HAL_PROPERTY_TYPE_INT32, addr, NULL);
+    HAL_PROPERTY_TYPE_INT32, addr, "info.bus",
+    HAL_PROPERTY_TYPE_STRING, "usb_device", NULL);
 
   if (device)
     {
@@ -276,6 +283,23 @@ hf_usb2_devd_remove (const char *name,
   return FALSE;
 }
 
+static gboolean
+hf_usb2_devd_notify (const char *system,
+		     const char *subsystem,
+		     const char *type,
+		     const char *data)
+{
+  if (! data || strcmp(system, "DEVFS") || strcmp(subsystem, "CDEV") ||
+      (strcmp(type, "CREATE") && strcmp(type, "DESTROY")))
+    return FALSE;
+
+  if (! strncmp(data, "cdev=ugen", strlen("cdev=ugen")) ||
+      ! strncmp(data, "cdev=usb", strlen("cdev=usb")))
+    return TRUE;
+
+  return FALSE;
+}
+
 HFHandler hf_usb2_handler = {
   .privileged_init	= hf_usb2_privileged_init,
   .probe		= hf_usb2_probe
@@ -283,5 +307,6 @@ HFHandler hf_usb2_handler = {
 
 HFDevdHandler hf_usb2_devd_handler = {
   .add =	hf_usb2_devd_add,
-  .remove =	hf_usb2_devd_remove
+  .remove =	hf_usb2_devd_remove,
+  .notify =     hf_usb2_devd_notify
 };
