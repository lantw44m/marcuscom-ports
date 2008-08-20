--- src/malloc.h.orig	2008-08-20 13:18:28.404065000 -0400
+++ src/malloc.h	2008-08-20 13:19:57.000000000 -0400
@@ -31,7 +31,11 @@
 #define ca_free free
 #define ca_malloc0(size) calloc(1, (size))
 #define ca_strdup strdup
+#ifdef HAVE_STRNDUP
 #define ca_strndup strndup
+#else
+char *ca_strndup(const char *s, size_t n);
+#endif
 
 void* ca_memdup(const void* p, size_t size);
 
