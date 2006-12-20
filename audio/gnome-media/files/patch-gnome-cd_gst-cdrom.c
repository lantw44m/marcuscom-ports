--- gnome-cd/gst-cdrom.c.orig	Tue Dec 19 20:44:39 2006
+++ gnome-cd/gst-cdrom.c	Wed Dec 20 00:48:26 2006
@@ -44,13 +44,17 @@
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDIOCCAPABILITY
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDIOCGETVOL
+struct ioc_vol vol_value;
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR &vol_value
 # define GST_CDROM_IOCTL_EJECT_REQUEST         CDIOCEJECT
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 # define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDIOCGETVOL
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR 0
 # define GST_CDROM_IOCTL_EJECT_REQUEST         CDIOCEJECT
 #else
 # define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST  CDROM_GET_CAPABILITY
+# define GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR 0
 # define GST_CDROM_IOCTL_EJECT_REQUEST         CDROMEJECT
 #endif
 
@@ -187,7 +191,7 @@ gst_cdrom_is_cdrom_device (GnomeCDRom * 
 
     fd = open (device, O_RDONLY | O_NONBLOCK);
     if (fd >= 0) {
-      if (ioctl (fd, GST_CDROM_IOCTL_CDCAPABILITY_REQUEST, 0) >= 0) {
+      if (ioctl (fd, GST_CDROM_IOCTL_CDCAPABILITY_REQUEST, GST_CDROM_IOCTL_CDCAPABILITY_REQUEST_ADDR) >= 0) {
         res = TRUE;
       } else {
         GST_DEBUG ("ioctl() failed: %s", g_strerror (errno));
