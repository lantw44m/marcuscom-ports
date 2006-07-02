--- hald/freebsd/hf-ata.c	7 May 2006 00:27:55 -0000	1.35
+++ hald/freebsd/hf-ata.c	2 Jul 2006 05:15:18 -0000
@@ -87,7 +87,11 @@
 static HalDevice *
 hf_ata_block_device_new (HalDevice *parent,
 			 int ms,
+#ifdef IOCATADEVICES
 			 const struct ata_ioc_devices *devices)
+#else
+                         const struct ata_cmd *devices)
+#endif
 {
   HalDevice *device;
   const struct ata_params *params;
@@ -96,14 +100,26 @@
   g_return_val_if_fail(HAL_IS_DEVICE(parent), NULL);
   g_return_val_if_fail(devices != NULL, NULL);
 
+#ifdef IOCATADEVICES
   params = &devices->params[ms];
+#else
+  params = &devices->u.param.params[ms];
+#endif
   vendor = hf_ata_get_vendor(params->model);
 
   device = hf_device_new(parent);
 
+#ifdef IOCATADEVICES
   hf_devtree_device_set_name(device, devices->name[ms]);
+#else
+  hf_devtree_device_set_name(device, devices->u.param.name[ms]);
+#endif
 
+#ifdef IOCATADEVICES
   hf_block_device_enable(device, devices->name[ms]);
+#else
+  hf_block_device_enable(device, devices->u.param.name[ms]);
+#endif
   hf_storage_device_enable(device);
 
   hal_device_property_set_string(device, "info.product", params->model);
@@ -148,20 +164,40 @@
 static void
 hf_ata_probe_devices (HalDevice *ide_host)
 {
+#ifdef IOCATADEVICES
   struct ata_ioc_devices devices;
+#else
+  struct ata_cmd devices;
+#endif
   int i;
 
   g_return_if_fail(HAL_IS_DEVICE(ide_host));
 
+#ifdef IOCATADEVICES
   devices.channel = hal_device_property_get_int(ide_host, "ide_host.number");
   if (ioctl(hf_ata_fd, IOCATADEVICES, &devices) < 0)
     {
       HAL_WARNING(("unable to probe devices of ATA channel %i: %s", devices.channel, g_strerror(errno)));
       return;
     }
+#else
+  memset(&devices, 0, sizeof(devices));
+  devices.cmd = ATAGPARM;
+  devices.device = -1;
+  devices.channel = hal_device_property_get_int(ide_host, "ide_host.number");
+  if (ioctl(hf_ata_fd, IOCATA, &devices) < 0)
+    {
+      HAL_WARNING(("unable to probe devices of ATA channel %i: %s", devices.channel, g_strerror(errno)));
+      return;
+    }
+#endif
 
   for (i = 0; i < 2; i++)
+#ifdef IOCATADEVICES
     if (*devices.name[i])
+#else
+    if (*devices.u.param.name[i])
+#endif
       {
 	HalDevice *ide_device;
 
@@ -176,7 +212,11 @@
 	  }
 
 	if (! hal_device_property_get_bool(ide_device, "info.ignore")
+#ifdef IOCATADEVICES
 	    && ! hf_devtree_find_from_name(hald_get_gdl(), devices.name[i]))
+#else
+	    && ! hf_devtree_find_from_name(hald_get_gdl(), devices.u.param.name[i]))
+#endif
 	  {
 	    HalDevice *block_device;
 
