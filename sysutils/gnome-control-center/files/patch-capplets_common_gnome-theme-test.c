--- capplets/common/gnome-theme-test.c.orig	Sat Jan 25 17:14:05 2003
+++ capplets/common/gnome-theme-test.c	Sat Jan 25 17:15:23 2003
@@ -10,10 +10,11 @@
 int
 main (int argc, char *argv[])
 {
+  gboolean monitor_not_added;
+  GList *themes, *list;
   gtk_init (&argc, &argv);
   gnome_vfs_init ();
-  gboolean monitor_not_added = FALSE;
-  GList *themes, *list;
+  monitor_not_added = FALSE;
 
   gnome_theme_init (&monitor_not_added);
   
