--- src/menucmd.c.orig	Mon May 24 20:24:15 2004
+++ src/menucmd.c	Mon May 24 20:24:50 2004
@@ -321,6 +321,7 @@
 cut_project(GtkWidget *w, gpointer data)
 {
 	GttProject *cut_prj;
+	GttProject *prj;
 
 	/* Do NOT cut unless the ctree window actually has focus.
 	 * Otherwise, it will lead to cutting mayhem. 
@@ -342,7 +343,7 @@
 
 	/* Update various subsystems */
 	/* Set the notes are to whatever the new focus project is. */
-	GttProject *prj = ctree_get_focus_project (global_ptw);
+	prj = ctree_get_focus_project (global_ptw);
 	notes_area_set_project (global_na, prj);
 						 
 	menu_set_states();      /* To enable paste menu item */
@@ -402,6 +403,7 @@
 copy_project(GtkWidget *w, gpointer data)
 {
 	GttProject *prj;
+	GList *n;
 	prj = ctree_get_focus_project (global_ptw);
 
 	if (!prj) return;
@@ -412,7 +414,7 @@
 	 * the list of earlier cut projects.  We do this in order
 	 * to allow the most recently copied project to be pasted
 	 * multiple times.  */
-	GList *n = cutted_project_list;
+	n = cutted_project_list;
 	for (n=cutted_project_list; n; n=n->next)
 	{
 		GttProject *p = n->data;
