--- gtk/gtkfilechooserdefault.c.orig	Wed Jul 27 15:02:39 2005
+++ gtk/gtkfilechooserdefault.c	Wed Jul 27 15:02:55 2005
@@ -1419,13 +1419,13 @@ shortcuts_append_desktop (GtkFileChooser
 {
   char *name;
   GtkFilePath *path;
+  const char *home = g_get_home_dir ();
 
   profile_start ("start", NULL);
 
 #ifdef G_OS_WIN32
   name = _gtk_file_system_win32_get_desktop ();
 #else
-  const char *home = g_get_home_dir ();
   if (home == NULL)
     {
       profile_end ("end - no home directory!?", NULL);
