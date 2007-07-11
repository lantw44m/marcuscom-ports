--- src/FreeType/fttools.c.orig	2007-07-11 12:09:47.000000000 -0400
+++ src/FreeType/fttools.c	2007-07-11 12:09:58.000000000 -0400
@@ -44,11 +44,9 @@
 #include "ft.h"
 
 /* backward compatibility hack */
-#if (FREETYPE_VERSION < 2001008)
 # ifndef ft_isdigit
 #  define ft_isdigit isdigit
 # endif
-#endif
 
 #ifndef LSBFirst
 #define LSBFirst 0
