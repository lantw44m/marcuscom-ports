--- plugins/shared-folder/install-shared.c.orig	Tue Jan 11 14:07:43 2005
+++ plugins/shared-folder/install-shared.c	Tue Jan 11 14:08:02 2005
@@ -132,12 +132,12 @@
 static void 
 accept_clicked(GnomeDruidPage *page, GtkWidget *druid, const char *id)
 {
-	g_print("\n\naccepting\n\n");
 	EMFolderTreeModel *model;
 	EMFolderTree *folder_tree;
 	GtkWidget *dialog ;
 	struct AcceptData *accept_data; 
 	char *uri;
+	g_print("\n\naccepting\n\n");
 	accept_data = g_new0(struct AcceptData, 1);
 	model = mail_component_peek_tree_model (mail_component_peek ());
 	folder_tree = (EMFolderTree *) em_folder_tree_new_with_model (model);
