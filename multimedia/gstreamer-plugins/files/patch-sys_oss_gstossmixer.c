--- sys/oss/gstossmixer.c.orig	Sun Nov 16 13:43:53 2003
+++ sys/oss/gstossmixer.c	Sun Nov 16 16:57:37 2003
@@ -399,7 +399,9 @@
   gint i, devmask;
   const GList *pads = gst_element_get_pad_list (GST_ELEMENT (oss));
   GstPadDirection dir = GST_PAD_UNKNOWN;
+#ifdef SOUND_MIXER_INFO
   struct mixer_info minfo;
+#endif
 
   g_return_if_fail (oss->mixer_fd == -1);
 
@@ -428,9 +430,13 @@
   }
 
   /* get name */
+#ifdef SOUND_MIXER_INFO
   if (ioctl (oss->mixer_fd, SOUND_MIXER_INFO, &minfo) == 0) {
     oss->device_name = g_strdup (minfo.name);
   }
+#else
+  oss->device_name = g_strdup ("FreeBSD Mixer");
+#endif
 
   /* build track list */
   for (i = 0; i < SOUND_MIXER_NRDEVICES; i++) {
