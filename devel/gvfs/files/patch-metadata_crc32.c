--- metadata/crc32.c.orig	2009-07-24 15:23:01.000000000 -0400
+++ metadata/crc32.c	2009-07-24 15:23:36.000000000 -0400
@@ -82,7 +82,7 @@ static const guint32 crcTable[256] = {
 };
 
 guint32
-crc32 (const void *ptr, size_t len)
+metadata_crc32 (const void *ptr, size_t len)
 {
   guint32 crc = 0xFFFFFFFF;
   const guint8 *bp = (const guint8 *) ptr;
