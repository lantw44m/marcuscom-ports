--- hald/freebsd/hf-usb.c.orig	2010-02-19 23:04:46.000000000 -0500
+++ hald/freebsd/hf-usb.c	2010-02-19 23:04:48.000000000 -0500
@@ -908,6 +908,8 @@ hf_usb_add_webcam_properties (HalDevice 
 
   hal_device_property_set_string(device, "info.category", "video4linux");
   hal_device_add_capability(device, "video4linux");
+  hal_device_add_capability(device, "video4linux.video_capture");
   hf_device_property_set_string_printf(device, "video4linux.device", "/dev/video%i", unit);
   hal_device_property_set_string(device, "info.product", "Video Device");
+  hal_device_property_set_string(device, "video4linux.version", "1");
 }
