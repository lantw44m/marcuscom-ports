--- src/sj-metadata-cdtext.c.orig	Mon Nov  7 15:18:37 2005
+++ src/sj-metadata-cdtext.c	Mon Nov  7 15:18:57 2005
@@ -35,8 +35,10 @@
 #include "sj-error.h"
 #include "sj-util.h"
 
+#if 0
 #if CDIO_API_VERSION != 2
 #error Unknown libcdio version!
+#endif
 #endif
 
 static GError* cdtext_get_new_error (SjMetadata *metadata);
