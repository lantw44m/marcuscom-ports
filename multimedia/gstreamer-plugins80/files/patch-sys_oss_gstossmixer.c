--- sys/oss/gstossmixer.c.orig	Sat Nov 15 02:02:25 2003
+++ sys/oss/gstossmixer.c	Sat Nov 15 02:10:18 2003
@@ -399,7 +399,6 @@
   gint i, devmask;
   const GList *pads = gst_element_get_pad_list (GST_ELEMENT (oss));
   GstPadDirection dir = GST_PAD_UNKNOWN;
-  struct mixer_info minfo;
 
   g_return_if_fail (oss->mixer_fd == -1);
 
@@ -428,9 +427,7 @@
   }
 
   /* get name */
-  if (ioctl (oss->mixer_fd, SOUND_MIXER_INFO, &minfo) == 0) {
-    oss->device_name = g_strdup (minfo.name);
-  }
+  oss->device_name = g_strdup ("FreeBSD Mixer");
 
   /* build track list */
   for (i = 0; i < SOUND_MIXER_NRDEVICES; i++) {
