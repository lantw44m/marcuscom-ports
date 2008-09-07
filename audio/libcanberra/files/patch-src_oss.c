--- src/oss.c.orig	2008-09-07 12:54:12.000000000 -0400
+++ src/oss.c	2008-09-07 12:54:18.000000000 -0400
@@ -258,7 +258,7 @@ static int open_oss(ca_context *c, struc
             val = AFMT_S16_NE;
             break;
         case CA_SAMPLE_S16RE:
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if _BYTE_ORDER == _LITTLE_ENDIAN
             val = AFMT_S16_BE;
 #else
             val = AFMT_S16_LE;
