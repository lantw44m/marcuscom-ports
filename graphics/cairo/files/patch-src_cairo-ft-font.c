--- src/cairo-ft-font.c.orig	Tue Aug 16 14:33:55 2005
+++ src/cairo-ft-font.c	Tue Aug 16 14:43:47 2005
@@ -44,6 +44,10 @@
 #include <fontconfig/fontconfig.h>
 #include <fontconfig/fcfreetype.h>
 
+#include <sys/types.h>
+#include <time.h>
+#include <unistd.h>
+
 #include <ft2build.h>
 #include FT_FREETYPE_H
 #include FT_OUTLINE_H
@@ -257,7 +261,12 @@ _cairo_ft_unscaled_font_init_key (cairo_
     key->id = id;
 
     /* 1607 is just an arbitrary prime. */
-    hash = _cairo_hash_string (filename);
+    if (filename != NULL) {
+        hash = _cairo_hash_string (filename);
+    } else {
+	srandom(time(NULL) * getpid());
+	hash = random();
+    }
     hash += ((unsigned long) id) * 1607;
 	
     key->base.hash_entry.hash = hash;
