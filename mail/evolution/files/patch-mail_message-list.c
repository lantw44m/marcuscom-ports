--- mail/message-list.c.orig	Sat Jun  5 20:05:13 2004
+++ mail/message-list.c	Sat Jun  5 20:08:01 2004
@@ -2129,6 +2129,7 @@
 	ETreeModel *etm = ml->model;
 	ETreePath *top;
 	char *saveuid = NULL;
+	GPtrArray *selected;
 
 #ifdef TIMEIT
 	struct timeval start, end;
@@ -2156,7 +2157,7 @@
 #ifndef BROKEN_ETREE
 	if (top == NULL || changes == NULL) {
 #else
-		GPtrArray *selected = message_list_get_selected(ml);
+		selected = message_list_get_selected(ml);
 #endif
 		e_tree_memory_freeze(E_TREE_MEMORY(etm));
 		clear_tree (ml);
@@ -2455,6 +2456,7 @@
 	ETreePath node;
 	char *saveuid = NULL;
 	int i;
+	GPtrArray *selected;
 
 #ifdef TIMEIT
 	struct timeval start, end;
@@ -2472,7 +2474,7 @@
 		build_flat_diff(ml, changes);
 	} else {
 #else
-		GPtrArray *selected = message_list_get_selected(ml);
+		selected = message_list_get_selected(ml);
 #endif
 		e_tree_memory_freeze(E_TREE_MEMORY(etm));
 		clear_tree (ml);
