--- libwnck/window.c.orig	Tue Aug 17 15:47:33 2004
+++ libwnck/window.c	Tue Aug 17 15:47:46 2004
@@ -1064,11 +1064,11 @@
 gboolean
 wnck_window_is_most_recently_activated (WnckWindow *window)
 {
-  g_return_val_if_fail (WNCK_IS_WINDOW (window), FALSE);
-
   WnckWindow * current;
   WnckWindow * previous;
   WnckWindow * most_recently_activated_window;
+  g_return_val_if_fail (WNCK_IS_WINDOW (window), FALSE);
+
 
   current  = wnck_screen_get_active_window (window->priv->screen);
   previous = wnck_screen_get_previously_active_window (window->priv->screen);
