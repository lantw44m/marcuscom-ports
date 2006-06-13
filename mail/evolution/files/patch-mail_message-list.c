--- mail/message-list.c.orig	Tue Jun 13 12:19:43 2006
+++ mail/message-list.c	Tue Jun 13 12:20:11 2006
@@ -56,11 +56,13 @@
 #include "misc/e-gui-utils.h"
 
 #include "table/e-cell-checkbox.h"
+#include "table/e-cell-hbox.h"
 #include "table/e-cell-date.h"
 #include "table/e-cell-size.h"
 #include "table/e-cell-text.h"
 #include "table/e-cell-toggle.h"
 #include "table/e-cell-tree.h"
+#include "table/e-cell-vbox.h"
 #include "table/e-tree-memory-callbacks.h"
 #include "table/e-tree-memory.h"
 
