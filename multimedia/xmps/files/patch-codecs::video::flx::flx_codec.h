
$FreeBSD: ports/multimedia/xmps/files/patch-codecs::video::flx::flx_codec.h,v 1.1 2001/02/04 22:01:32 sobomax Exp $

--- codecs/video/flx/flx_codec.h.orig	Wed Nov  1 20:46:14 2000
+++ codecs/video/flx/flx_codec.h	Sun Feb  4 22:55:34 2001
@@ -52,7 +52,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#include <SDL/SDL.h>
+#include <SDL.h>
 
 typedef struct {
 
