--- logview/log_repaint.c.orig	Mon Aug  1 01:59:45 2005
+++ logview/log_repaint.c	Mon Aug  1 01:59:55 2005
@@ -413,8 +413,7 @@ logview_draw_log_lines (LogviewWindow *w
                 utf8 = GetDateHeader (line);
                 gtk_tree_store_append (GTK_TREE_STORE (model), &iter, NULL);
                 gtk_tree_store_set (GTK_TREE_STORE (model), &iter,
-                                    DATE, utf8, HOSTNAME, FALSE,
-                                    PROCESS, FALSE, MESSAGE, FALSE, -1);
+                                    DATE, utf8, -1);
                 
                 /* store pointer to the date headers, using the month and day as the key */
                 
