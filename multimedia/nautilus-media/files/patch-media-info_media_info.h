--- media-info/media-info.h.orig	Fri Dec 12 13:06:42 2003
+++ media-info/media-info.h	Fri Dec 12 13:11:14 2003
@@ -35,7 +35,7 @@
 
   GstMediaInfoPriv *priv;
 
-  gpointer _gst_reserved[GST_PADDING];
+  GST_OBJECT_PADDING
 };
 
 struct _GstMediaInfoClass
@@ -45,7 +45,7 @@
   /* signals */
   void (*media_info_signal) 		(GstMediaInfo *gst_media_info);
 
-  gpointer _gst_reserved[GST_PADDING];
+  GST_OBJECT_PADDING
 };
 
 /* structure for "physical" stream,
