--- calendar/libical/src/libical/icaltz-util.c.orig	2007-08-27 15:06:14.000000000 -0500
+++ calendar/libical/src/libical/icaltz-util.c	2007-08-27 15:07:36.000000000 -0500
@@ -21,12 +21,23 @@
  */
 
 #include <string.h>
+#ifdef __FreeBSD__ /* FreeBSD */
+#include <sys/endian.h>
+#define __BYTE_ORDER            _BYTE_ORDER
+#define __LITTLE_ENDIAN         _LITTLE_ENDIAN
+#define __BIG_ENDIAN            _BIG_ENDIAN
+
+#define bswap_16                bswap16
+#define bswap_32                bswap32
+#define bswap_64                bswap64
+#else /* FreeBSD */
 #if defined(sun) && defined(__SVR4)
 #include <sys/byteorder.h>
 #else
 #include <byteswap.h>
 #include <endian.h>
 #endif
+#endif /* FreeBSD */
 #include <limits.h>
 #include <time.h>
 #include <stdlib.h>
