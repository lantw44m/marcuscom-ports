--- src/window.c.orig	Wed Feb 23 01:24:01 2005
+++ src/window.c	Wed Feb 23 01:24:17 2005
@@ -648,7 +648,7 @@
       parent = meta_display_lookup_x_window (window->display,
                                              window->xtransient_for);
 
-      if (parent)
+      if (parent && parent->workspace)
         {
           meta_topic (META_DEBUG_PLACEMENT,
                       "Putting window %s on same workspace as parent %s\n",
