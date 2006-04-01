--- sys/oss/gstosssrc.c.orig	Sat Apr  1 18:22:52 2006
+++ sys/oss/gstosssrc.c	Sat Apr  1 18:22:56 2006
@@ -94,6 +94,22 @@ static GstStaticPadTemplate osssrc_src_f
     GST_PAD_SRC,
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
+        "endianness = (int) { " G_STRINGIFY (G_BYTE_ORDER) " }, "
+        "signed = (boolean) { TRUE, FALSE }, "
+        "width = (int) 24, "
+        "depth = (int) 24, "
+        "rate = (int) [ 1, MAX ], " "channels = (int) [ 1, 2 ]; "
+	"audio/x-raw-int, "
+#endif
         "endianness = (int) { " G_STRINGIFY (G_BYTE_ORDER) " }, "
         "signed = (boolean) { TRUE, FALSE }, "
         "width = (int) 16, "
