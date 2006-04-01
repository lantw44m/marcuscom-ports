--- sys/oss/gstosssink.c.orig	Sat Apr  1 18:22:44 2006
+++ sys/oss/gstosssink.c	Sat Apr  1 18:23:25 2006
@@ -98,6 +98,22 @@ static GstStaticPadTemplate osssink_sink
     GST_PAD_SINK,
     GST_PAD_ALWAYS,
     GST_STATIC_CAPS ("audio/x-raw-int, "
+#if defined(AFMT_S32_LE)
+	"endianness = (int) { " G_STRINGIFY (G_BYTE_ORDER) " }, "
+	"signed = (boolean) { TRUE, FALSE }, "
+	"width = (int) 32, "
+	"depth = (int) 32, "
+	"rate = (int) [ 1, MAX ], " "channels = (int) [ 1, 2 ]; "
+	"audio/x-raw-int, "
+#endif
+#if defined(AFMT_S24_LE)
+	"endianness = (int) { " G_STRINGIFY (G_BYTE_ORDER) " }, "
+	"signed = (boolean) { TRUE, FALSE }, "
+	"width = (int) 24, "
+	"depth = (int) 24, "
+	"rate = (int) [ 1, MAX ], " "channels = (int) [ 1, 2 ]; "
+	"audio/x-raw-int, "
+#endif
         "endianness = (int) { " G_STRINGIFY (G_BYTE_ORDER) " }, "
         "signed = (boolean) { TRUE, FALSE }, "
         "width = (int) 16, "
