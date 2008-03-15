--- hald/freebsd/hf-util.h.orig	2008-03-15 14:27:35.000000000 -0400
+++ hald/freebsd/hf-util.h	2008-03-15 14:27:46.000000000 -0400
@@ -110,7 +110,7 @@ int hf_runner_run_sync (HalDevice *devic
 
 int hf_strv_find (char **strv, const char *elem);
 
-char *hf_str_no_slashes (const char *str);
+char *hf_str_escape (const char *str);
 
 HalDevice *hf_device_store_match (HalDeviceStore *store, ...);
 
