--- gst/gstthreaddummy.c.orig	Sat Jan 25 18:06:11 2003
+++ gst/gstthreaddummy.c	Sat Jan 25 18:06:36 2003
@@ -17,7 +17,9 @@
  * Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include <sys/time.h>
+#include <unistd.h>
 #include <glib.h>
 #include "gstlog.h"
 
