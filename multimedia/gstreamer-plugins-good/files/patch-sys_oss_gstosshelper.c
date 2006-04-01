--- sys/oss/gstosshelper.c.orig	Sat Apr  1 18:22:31 2006
+++ sys/oss/gstosshelper.c	Sat Apr  1 18:22:38 2006
@@ -102,6 +102,21 @@ gst_oss_helper_probe_caps (gint fd)
   else
     format_mask |= AFMT_S16_BE | AFMT_U16_BE;
 
+#if defined(AFMT_S24_LE)
+  if (G_BYTE_ORDER == G_LITTLE_ENDIAN)
+    format_mask |= AFMT_S24_LE | AFMT_U24_LE;
+  else
+    format_mask |= AFMT_S24_BE | AFMT_U24_BE;
+#endif
+
+#if defined(AFMT_S32_LE)
+  if (G_BYTE_ORDER == G_LITTLE_ENDIAN)
+    format_mask |= AFMT_S32_LE | AFMT_U32_LE;
+  else
+    format_mask |= AFMT_S32_BE | AFMT_U32_BE;
+#endif
+
+
   caps = gst_caps_new_empty ();
 
   /* assume that the most significant bit of format_mask is 0 */
@@ -202,6 +217,50 @@ gst_oss_helper_get_format_structure (uns
       sign = FALSE;
       width = 16;
       break;
+#if defined(AFMT_S24_LE)
+    case AFMT_S24_LE:
+      endianness = G_LITTLE_ENDIAN;
+      sign = TRUE;
+      width = 24;
+      break;
+    case AFMT_S24_BE:
+      endianness = G_BIG_ENDIAN;
+      sign = TRUE;
+      width = 24;
+      break;
+    case AFMT_U24_LE:
+      endianness = G_LITTLE_ENDIAN;
+      sign = FALSE;
+      width = 24;
+      break;
+    case AFMT_U24_BE:
+      endianness = G_BIG_ENDIAN;
+      sign = FALSE;
+      width = 24;
+      break;
+#endif
+#if defined(AFMT_S32_LE)
+    case AFMT_S32_LE:
+      endianness = G_LITTLE_ENDIAN;
+      sign = TRUE;
+      width = 32;
+      break;
+    case AFMT_S32_BE:
+      endianness = G_BIG_ENDIAN;
+      sign = TRUE;
+      width = 32;
+      break;
+    case AFMT_U32_LE:
+      endianness = G_LITTLE_ENDIAN;
+      sign = FALSE;
+      width = 32;
+      break;
+    case AFMT_U32_BE:
+      endianness = G_BIG_ENDIAN;
+      sign = FALSE;
+      width = 32;
+      break;
+#endif
     default:
       g_assert_not_reached ();
       return NULL;
@@ -232,6 +291,11 @@ gst_oss_helper_rate_probe_check (GstOssP
 
   probe->rates = g_array_new (FALSE, FALSE, sizeof (int));
 
+  probe->min = 8000;
+  probe->max = 100000;
+  result = FALSE;
+  goto out;
+
   probe->min = gst_oss_helper_rate_check_rate (probe, 1000);
   n_checks++;
   probe->max = gst_oss_helper_rate_check_rate (probe, 100000);
@@ -312,6 +376,7 @@ gst_oss_helper_rate_probe_check (GstOssP
 
     g_free (range);
   }
+out:
 
   while ((range = g_queue_pop_head (ranges))) {
     g_free (range);
