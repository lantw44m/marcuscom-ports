--- libanjuta/anjuta-children.c.orig	Sun May 22 21:31:19 2005
+++ libanjuta/anjuta-children.c	Sun May 22 21:31:36 2005
@@ -17,6 +17,8 @@
  *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/signal.h>
+
 #include <libanjuta/anjuta-children.h>
 
 static GList *registered_child_processes = NULL;
