--- src/af/util/xp/ut_string_class.cpp.orig	Thu Jun 17 15:00:46 2004
+++ src/af/util/xp/ut_string_class.cpp	Thu Jun 17 15:02:15 2004
@@ -28,6 +28,7 @@
 #include <locale.h>
 #include <ctype.h>
 #include <stdarg.h>
+#include <glib.h>
 
 #include "ut_string.h"
 #include "ut_string_class.h"
@@ -342,13 +343,13 @@
   return len;
 }
 
+#define VA_COPY G_VA_COPY
+
 #if !defined (VA_COPY)
 #  if defined (__GNUC__) && defined (__PPC__) && (defined (_CALL_SYSV) || defined (_WIN32) || defined(WIN32)) || defined(__s390__) || defined(__x86_64__)
 #  define VA_COPY(ap1, ap2)	  (*(ap1) = *(ap2))
 #  elif defined (VA_COPY_AS_ARRAY)
 #  define VA_COPY(ap1, ap2)	  memmove ((ap1), (ap2), sizeof (va_list))
-#  elif defined (__GNUC__) && defined (__va_copy)
-#  define VA_COPY(ap1,ap2)     __va_copy((ap1),(ap2))
 #  else /* va_list is a pointer */
 #  define VA_COPY(ap1, ap2)	  ((ap1) = (ap2))
 #  endif /* va_list is a pointer */
