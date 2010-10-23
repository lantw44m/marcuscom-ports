--- engine/dconf-engine.c.orig	2010-10-21 13:49:19.000000000 +0200
+++ engine/dconf-engine.c	2010-10-21 14:16:31.000000000 +0200
@@ -144,6 +144,7 @@ dconf_engine_setup_user (DConfEngine *en
 
           if (fd >= 0)
             {
+/*
               if (posix_fallocate (fd, 0, 1) == 0)
                 {
                   engine->shm = mmap (NULL, 1, PROT_READ, MAP_SHARED, fd, 0);
@@ -151,7 +152,7 @@ dconf_engine_setup_user (DConfEngine *en
                   if (engine->shm == MAP_FAILED)
                     engine->shm = NULL;
                 }
-
+*/
               close (fd);
             }
         }
