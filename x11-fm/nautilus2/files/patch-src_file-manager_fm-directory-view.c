--- src/file-manager/fm-directory-view.c.orig	Thu Oct  2 23:30:40 2003
+++ src/file-manager/fm-directory-view.c	Thu Oct  2 23:52:04 2003
@@ -4314,19 +4314,25 @@
 
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_MENU_PATH_SCRIPTS, 
-				    !any_scripts);
+				    FALSE);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_SCRIPTS, 
+				    FALSE);
+	nautilus_bonobo_set_hidden (view->details->ui,
+				    FM_DIRECTORY_VIEW_MENU_PATH_SCRIPTS_PLACEHOLDER,
+				    !any_scripts);
+	nautilus_bonobo_set_hidden (view->details->ui,
+				    FM_DIRECTORY_VIEW_POPUP_PATH_BACKGROUND_SCRIPTS_PLACEHOLDER,
 				    !any_scripts);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_BACKGROUND_SCRIPTS, 
-				    !any_scripts);
+				    FALSE);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_MENU_PATH_SCRIPTS_SEPARATOR, 
 				    !any_scripts);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_SCRIPTS_SEPARATOR, 
-				    !any_scripts);
+				    FALSE);
 	nautilus_bonobo_set_hidden (view->details->ui, 
 				    FM_DIRECTORY_VIEW_POPUP_PATH_BACKGROUND_SCRIPTS_SEPARATOR, 
 				    !any_scripts);
@@ -5149,10 +5149,11 @@
 			GList *selection,
 			gint selection_count)
 {
-	selection_count = g_list_length (selection);
 	gboolean can_paste_files_into;
 	gboolean selection_is_read_only;
 	gboolean is_read_only;
+
+	selection_count = g_list_length (selection);
 
 	selection_is_read_only = selection_count == 1
 		&& !nautilus_file_can_write (NAUTILUS_FILE (selection->data));
