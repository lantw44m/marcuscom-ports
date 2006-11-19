--- src/fr-command-iso.c.orig	Tue Nov  7 04:03:30 2006
+++ src/fr-command-iso.c	Sat Nov 18 20:22:18 2006
@@ -159,6 +159,7 @@ fr_command_iso_extract (FRCommand  *comm
 			gboolean    junk_paths,
 			const char *password)
 {
+	FRCommandIso  *comm_iso = FR_COMMAND_ISO (comm);
 	char  *e_dest_dir;
 	GList *scan;
 
@@ -166,6 +167,7 @@ fr_command_iso_extract (FRCommand  *comm
 
 	for (scan = file_list; scan; scan = scan->next) {
 		char       *path = scan->data;
+		char       *extract_path;
 		const char *filename;
                 char       *file_dir, *e_temp_dest_dir = NULL, *temp_dest_dir = NULL;
 	
@@ -180,6 +182,8 @@ fr_command_iso_extract (FRCommand  *comm
 		if (e_temp_dest_dir == NULL) 
 			continue;
 
+		extract_path = g_build_filename (comm_iso->cur_path, path, NULL);
+
 		temp_dest_dir = unescape_str (e_temp_dest_dir);
 		ensure_dir_exists (temp_dest_dir, 0700);
 
@@ -188,13 +192,14 @@ fr_command_iso_extract (FRCommand  *comm
 		fr_process_add_arg (comm->process, "-i");
 		fr_process_add_arg (comm->process, comm->e_filename);
 		fr_process_add_arg (comm->process, "-x");
-		fr_process_add_arg (comm->process, path);
+		fr_process_add_arg (comm->process, extract_path);
 		fr_process_add_arg (comm->process, ">");
 		fr_process_add_arg (comm->process, filename);
 		fr_process_end_command (comm->process);
 	
 		g_free (e_temp_dest_dir);
 		g_free (temp_dest_dir);
+		g_free (extract_path);
 	}
 
 	g_free (e_dest_dir);
