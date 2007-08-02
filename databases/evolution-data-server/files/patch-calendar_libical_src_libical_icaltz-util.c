--- calendar/libical/src/libical/icaltz-util.c.orig	2007-08-01 03:16:33.000000000 -0400
+++ calendar/libical/src/libical/icaltz-util.c	2007-08-01 03:18:44.000000000 -0400
@@ -21,8 +21,19 @@
  */
 
 #include <string.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define __BYTE_ORDER            _BYTE_ORDER
+#define __LITTLE_ENDIAN         _LITTLE_ENDIAN
+#define __BIG_ENDIAN            _BIG_ENDIAN
+
+#define bswap_16                bswap16
+#define bswap_32                bswap32
+#define bswap_64                bswap64
+#else
 #include <byteswap.h>
 #include <endian.h>
+#endif
 #include <limits.h>
 #include <time.h>
 #include <stdlib.h>
