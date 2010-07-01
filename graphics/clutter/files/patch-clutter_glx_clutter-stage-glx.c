--- clutter/glx/clutter-stage-glx.c.orig	2010-06-30 20:07:53.000000000 +0200
+++ clutter/glx/clutter-stage-glx.c	2010-06-30 20:37:00.000000000 +0200
@@ -476,8 +476,8 @@ wait_for_vblank (ClutterBackendGLX *back
                                     (retraceCount + 1) % 2,
                                     &retraceCount);
     }
-  else
 #ifdef __linux__
+  else
     {
       drm_wait_vblank_t blank;
 
