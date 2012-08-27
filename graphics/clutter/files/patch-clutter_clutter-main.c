--- clutter/clutter-main.c.orig	2012-06-19 09:56:35.000000000 +0200
+++ clutter/clutter-main.c	2012-07-15 13:09:09.000000000 +0200
@@ -227,6 +227,7 @@
 static void
 clutter_threads_impl_unlock (void)
 {
+  g_mutex_trylock (&clutter_threads_mutex);
   g_mutex_unlock (&clutter_threads_mutex);
 }
 
