$FreeBSD: ports/graphics/py-visual/files/patch-src-python-cvisualmodule.cpp,v 1.1 2007/03/09 17:15:06 nivit Exp $
--- src/python/cvisualmodule.cpp	Tue Mar  6 11:45:52 2007
+++ src/python/cvisualmodule.cpp.port	Tue Mar  6 11:46:04 2007
@@ -5,6 +5,7 @@
 // See the file license.txt for complete license terms.
 // See the file authors.txt for a complete list of contributors.
 
+#include <iostream>
 #include <stdexcept>
 #include <exception>
 
