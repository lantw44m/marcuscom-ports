
$FreeBSD: ports/mail/evolution/files/patch-camel::camel-store.h,v 1.2 2003/06/11 06:16:16 marcus Exp $

--- camel/camel-store.h	2001/09/04 16:45:47	1.1
+++ camel/camel-store.h	2001/09/04 16:46:32
@@ -33,6 +33,7 @@
 #pragma }
 #endif /* __cplusplus }*/
 
+#include <sys/types.h>
 #include <camel/camel-object.h>
 #include <camel/camel-service.h>
 
