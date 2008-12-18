--- src/oss.c.orig	2008-08-20 22:11:17.000000000 -0400
+++ src/oss.c	2008-12-18 02:04:42.000000000 -0500
@@ -235,7 +235,7 @@ static int open_oss(ca_context *c, struc
     ca_return_val_if_fail(c, CA_ERROR_INVALID);
     ca_return_val_if_fail(c->private, CA_ERROR_STATE);
     ca_return_val_if_fail(out, CA_ERROR_INVALID);
-    ca_return_val_if_fail(ca_sound_file_get_nchannels(out->file) > 2, CA_ERROR_NOTSUPPORTED);
+    ca_return_val_if_fail(ca_sound_file_get_nchannels(out->file) <= 2, CA_ERROR_NOTSUPPORTED);
 
     p = PRIVATE(c);
 
@@ -258,7 +258,7 @@ static int open_oss(ca_context *c, struc
             val = AFMT_S16_NE;
             break;
         case CA_SAMPLE_S16RE:
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
             val = AFMT_S16_BE;
 #else
             val = AFMT_S16_LE;
