--- ext/ffmpeg/gstffmpegcodecmap.c.orig	Sat Nov 15 02:22:47 2003
+++ ext/ffmpeg/gstffmpegcodecmap.c	Sat Nov 15 02:22:27 2003
@@ -44,7 +44,7 @@
 		      "height", GST_PROPS_INT (context->height),\
 		      "framerate", GST_PROPS_FLOAT (            \
 				1.*context->frame_rate/         \
-				context->frame_rate_base),      \
+				context->frame_rate_base) ,      \
 		      ##props)					\
 	:							\
 	GST_CAPS_NEW (name,					\
@@ -52,7 +52,7 @@
 		      "width",  GST_PROPS_INT_RANGE (16, 4096),	\
 		      "height", GST_PROPS_INT_RANGE (16, 4096),	\
 		      "framerate", GST_PROPS_FLOAT_RANGE (0,    \
-						G_MAXFLOAT),    \
+						G_MAXFLOAT) ,    \
 		      ##props)
 
 /* same for audio - now with channels/sample rate
@@ -63,13 +63,13 @@
 	GST_CAPS_NEW (name,						\
 		      mimetype,						\
 		      "rate",     GST_PROPS_INT (context->sample_rate),	\
-		      "channels", GST_PROPS_INT (context->channels),	\
+		      "channels", GST_PROPS_INT (context->channels) ,	\
 		      ##props)						\
 	:								\
 	GST_CAPS_NEW (name,						\
 		      mimetype,						\
 		      "rate",     GST_PROPS_INT_RANGE (8000, 96000),	\
-		      "channels", GST_PROPS_INT_RANGE (1, 2),		\
+		      "channels", GST_PROPS_INT_RANGE (1, 2) ,		\
 		      ##props)
 
 /* Convert a FFMPEG codec ID and optional AVCodecContext
