--- src/openfiles.c.orig	Fri Jan 14 03:16:02 2005
+++ src/openfiles.c	Fri Jan 14 03:16:34 2005
@@ -106,7 +106,7 @@
 	const glibtop_open_files_entry *o2 = b;
 
 	/* Falta manejar los diferentes tipos! */
-	return (o1->fd == o2->fd) && (o1->type == o1->type); // XXX!
+	return (o1->fd == o2->fd) && (o1->type == o1->type); /* XXX! */
 }
 
 
@@ -115,10 +115,10 @@
 {
 	ProcInfo *info;
 	GtkTreeModel *model;
-	glibtop_open_files_entry *openfiles;
-	glibtop_proc_open_files procmap;
 	GHashTable *new_maps;
 	gint i;
+	glibtop_open_files_entry *openfiles;
+	glibtop_proc_open_files procmap;
 
 	info = g_object_get_data (G_OBJECT (tree), "selected_info");
 	g_return_if_fail (info);
