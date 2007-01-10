--- src/fr-command-iso.c.orig	Mon Jan  8 17:06:36 2007
+++ src/fr-command-iso.c	Wed Jan 10 14:43:17 2007
@@ -164,6 +164,7 @@ fr_command_iso_extract (FRCommand  *comm
 			gboolean    junk_paths,
 			const char *password)
 {
+	FRCommandIso  *comm_iso = FR_COMMAND_ISO (comm);
 	char  *e_dest_dir;
 	char  *e_archive_filename;
 	GList *scan;
@@ -173,6 +174,7 @@ fr_command_iso_extract (FRCommand  *comm
 
 	for (scan = file_list; scan; scan = scan->next) {
 		char       *path = scan->data;
+		char       *extract_path;
 		const char *filename;
                 char       *file_dir, *e_temp_dest_dir = NULL, *temp_dest_dir = NULL;
 
@@ -187,6 +189,8 @@ fr_command_iso_extract (FRCommand  *comm
 		if (e_temp_dest_dir == NULL)
 			continue;
 
+		extract_path = g_build_filename (comm_iso->cur_path, path, NULL);
+
 		temp_dest_dir = unescape_str (e_temp_dest_dir);
 		ensure_dir_exists (temp_dest_dir, 0700);
 
@@ -195,13 +199,14 @@ fr_command_iso_extract (FRCommand  *comm
 		fr_process_add_arg (comm->process, "-i");
 		fr_process_add_arg (comm->process, e_archive_filename);
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
