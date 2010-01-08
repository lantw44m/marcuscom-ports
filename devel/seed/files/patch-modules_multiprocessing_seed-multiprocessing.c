--- modules/multiprocessing/seed-multiprocessing.c.orig	2010-01-07 19:08:08.000000000 -0500
+++ modules/multiprocessing/seed-multiprocessing.c	2010-01-07 19:08:20.000000000 -0500
@@ -183,7 +183,8 @@ SeedValue seed_pipe_add_watch(SeedContex
 seed_static_function pipe_funcs[] = {
   {"read", seed_pipe_read, 0},
   {"write", seed_pipe_write, 0},
-  {"add_watch", seed_pipe_add_watch, 0}
+  {"add_watch", seed_pipe_add_watch, 0},
+  {NULL, NULL, 0}
 };
 
 SeedObject
