--- media/liboggplay_audio/sydney_audio.h.orig	2008-11-24 21:38:34.000000000 +0000
+++ media/liboggplay_audio/sydney_audio.h	2008-11-24 21:39:10.000000000 +0000
@@ -32,7 +32,7 @@
 #   endif
 #elif defined(WIN32)
 #   define SA_LITTLE_ENDIAN 1
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #   if defined(__BIG_ENDIAN__)
 #       define SA_BIG_ENDIAN 1
 #   else
