--- lib/memmem.c.orig	2008-02-09 11:14:06.000000000 -0500
+++ lib/memmem.c	2008-02-09 11:16:51.000000000 -0500
@@ -31,8 +31,10 @@
  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  * SUCH DAMAGE.
  */
+#if !defined(__sun) && !defined(__FreeBSD__)
 #include "bbs.h"
-#ifndef SOLARIS
+#endif
+#ifndef __sun
 #include <sys/cdefs.h>
 #endif
 
