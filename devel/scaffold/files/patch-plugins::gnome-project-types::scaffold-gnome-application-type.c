--- plugins/gnome-project-types/scaffold-gnome-application-type.c.orig	Fri Oct 17 17:33:07 2003
+++ plugins/gnome-project-types/scaffold-gnome-application-type.c	Fri Oct 17 17:33:41 2003
@@ -79,7 +79,7 @@
 	g_message ("create_project_impl");
 
 	args = g_new0 (char *, 7);
-	args[0] = g_strdup ("/usr/bin/python");
+	args[0] = g_strdup ("/usr/local/bin/python");
 	args[1] = g_strdup ("scaffold-gnome-application-create.py");
 	args[2] = g_strdup (info->name);
 	args[3] = g_strdup (info->package);
