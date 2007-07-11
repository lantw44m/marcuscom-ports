--- daemon/getvt.c.orig	2007-07-11 13:06:10.000000000 -0400
+++ daemon/getvt.c	2007-07-11 13:13:29.000000000 -0400
@@ -102,6 +102,27 @@ gdm_get_current_vtnum (Display *display)
 	return num;
 }
 
+#if defined (GDM_USE_SYS_VT)
+#include <sys/vt.h>
+#elif defined (GDM_USE_CONSIO_VT)
+#include <sys/consio.h>
+
+static const char*
+__itovty (int val)
+{
+	static char str[8];
+	char* next = str + sizeof (str) - 1;
+
+	*next = '\0';
+	do {
+		*--next = "0123456789abcdefghigklmnopqrstuv"[val % 32];
+	} while (val /= 32);
+
+	return next;
+}
+#endif
+
+
 gchar *
 gdm_get_vt_device (int vtno)
 {
@@ -128,25 +149,6 @@ gdm_get_vt_device (int vtno)
 #define GDMCONSOLEDEVICE "/dev/console"
 #endif
 
-#if defined (GDM_USE_SYS_VT)
-#include <sys/vt.h>
-#elif defined (GDM_USE_CONSIO_VT)
-#include <sys/consio.h>
-
-static const char*
-__itovty (int val)
-{
-	static char str[8];
-	char* next = str + sizeof (str) - 1;
-
-	*next = '\0';
-	do {
-		*--next = "0123456789abcdefghigklmnopqrstuv"[val % 32];
-	} while (val /= 32);
-
-	return next;
-}
-#endif
 
 static int
 open_vt (int vtno)
