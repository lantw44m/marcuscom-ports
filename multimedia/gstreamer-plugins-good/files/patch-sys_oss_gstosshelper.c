--- sys/oss/gstosshelper.c.orig	Sat Apr  1 18:22:31 2006
+++ sys/oss/gstosshelper.c	Sat Apr  1 18:22:38 2006
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
