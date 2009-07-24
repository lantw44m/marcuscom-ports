--- metadata/crc32.h.orig	2009-07-24 15:24:08.000000000 -0400
+++ metadata/crc32.h	2009-07-24 15:23:51.000000000 -0400
@@ -46,4 +46,4 @@
 
 #include <glib.h>
 
-guint32 crc32(const void *ptr, size_t len);
+guint32 metadata_crc32(const void *ptr, size_t len);
