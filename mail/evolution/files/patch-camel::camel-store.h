
$FreeBSD: ports/mail/evolution/files/patch-camel::camel-store.h,v 1.3 2004/11/07 22:24:18 marcus Exp $

--- camel/camel-store.h	2001/09/04 16:45:47	1.1
+++ camel/camel-store.h	2001/09/04 16:46:32
@@ -33,6 +33,7 @@
 #pragma }
 #endif /* __cplusplus }*/
 
+#include <sys/types.h>
 #include <camel/camel-object.h>
 #include <camel/camel-service.h>
 
