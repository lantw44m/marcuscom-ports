--- gtk/gtkfilechooserdefault.c.orig	Wed Mar 10 16:11:22 2004
+++ gtk/gtkfilechooserdefault.c	Wed Mar 10 16:12:05 2004
@@ -757,10 +757,12 @@
   GtkFileFolder *parent_folder;
   GtkFileInfo *info;
 
+  info = NULL;
+
   if (!gtk_file_system_get_parent (file_system, path, &parent_path, error))
     return NULL;
 
-  parent_folder = gtk_file_system_get_folder (file_system, parent_path,
+  parent_folder = gtk_file_system_get_folder (file_system, parent_path ? parent_path : path,
 					      GTK_FILE_INFO_DISPLAY_NAME
 #if 0
 					      | GTK_FILE_INFO_ICON
