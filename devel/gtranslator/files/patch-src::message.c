
$FreeBSD: ports/devel/gtranslator/files/patch-src::message.c,v 1.3 2002/03/15 09:39:01 sobomax Exp $

--- src/message.c	2002/03/15 09:03:55	1.1
+++ src/message.c	2002/03/15 09:04:04
@@ -39,7 +39,7 @@
 #include "utils_gui.h"
 
 #include <string.h>
-#include <regex.h>
+#include <gnuregex.h>
 #include <gtk/gtk.h>
 
 #include <libgnomeui/gnome-app.h>
