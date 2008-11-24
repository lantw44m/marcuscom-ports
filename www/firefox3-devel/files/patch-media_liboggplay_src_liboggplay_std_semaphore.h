--- media/liboggplay/src/liboggplay/std_semaphore.h.orig	2008-11-24 20:59:17.000000000 +0000
+++ media/liboggplay/src/liboggplay/std_semaphore.h	2008-11-24 20:59:29.000000000 +0000
@@ -34,7 +34,7 @@
 
 #ifndef _STD_SEMAPHORE_H
 #define _STD_SEMAPHORE_H
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 #include <semaphore.h>
 #define SEM_CREATE(p,s) sem_init(&(p), 1, s)
 #define SEM_SIGNAL(p)   sem_post(&(p))
