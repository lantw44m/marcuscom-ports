--- src/fr-command-tar.c.orig	Mon Feb 16 10:53:20 2004
+++ src/fr-command-tar.c	Wed Feb 18 17:30:26 2004
@@ -83,6 +83,11 @@
 	return mktime (&tm);
 }
 
+static char *months[] = {
+    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct",
+    "Nov", "Dec"
+};
+
 
 static void
 process_line (char     *line, 
@@ -92,19 +97,34 @@
 	FRCommand   *comm = FR_COMMAND (data);
 	char       **fields;
 	const char  *name_field;
+	int          i;
+	struct tm    tm = {0, };
+	char       **time_fields;
 
 	g_return_if_fail (line != NULL);
 
 	fdata = file_data_new ();
 
-	fields = split_line (line, 5);
+	fields = split_line (line, 7);
 	fdata->size = atol (fields[2]);
-	fdata->modified = mktime_from_string (fields[3], fields[4]);
+	for (i = 0; i < 12; i++) {
+	    if (!strncmp(fields[3], months[i], 3)) break;
+	}
+	tm.tm_mon = i;
+	tm.tm_year = atoi (fields[6]) - 1900;
+	tm.tm_mday = atoi (fields[4]);
+	time_fields = g_strsplit(fields[5], ":", 2);
+	tm.tm_hour = atoi (time_fields[0]);
+	tm.tm_min = atoi (time_fields[1]);
+	tm.tm_sec = 0;
+	tm.tm_isdst = -1;
+	fdata->modified = mktime(&tm);
 	g_strfreev (fields);
+	g_strfreev (time_fields);
 
 	/* Full path */
 
-	name_field = get_last_field (line, 6);
+	name_field = get_last_field (line, 8);
 	fields = g_strsplit (name_field, " -> ", 2);
 
 	if (fields[1] == NULL) {
@@ -176,7 +196,7 @@
 				      process_line,
 				      comm);
 
-	fr_process_begin_command (comm->process, "gtar");
+	fr_process_begin_command (comm->process, "tar");
 	fr_process_add_arg (comm->process, "--force-local");
 	fr_process_add_arg (comm->process, "-tvf");
 	fr_process_add_arg (comm->process, comm->e_filename);
@@ -234,7 +254,7 @@
 				      process_line__add,
 				      comm);
 
-	fr_process_begin_command (comm->process, "gtar");
+	fr_process_begin_command (comm->process, "tar");
 	fr_process_add_arg (comm->process, "--force-local");
 	fr_process_add_arg (comm->process, "-v");
 
@@ -285,7 +305,7 @@
 				      process_line__delete,
 				      comm);
 
-	fr_process_begin_command (comm->process, "gtar");
+	fr_process_begin_command (comm->process, "tar");
 	fr_process_set_begin_func (comm->process, begin_func__delete, comm);
 	fr_process_add_arg (comm->process, "--force-local");
 	fr_process_add_arg (comm->process, "-v");
@@ -322,7 +342,7 @@
 				      process_line__extract,
 				      comm);
 
-	fr_process_begin_command (comm->process, "gtar");
+	fr_process_begin_command (comm->process, "tar");
 	fr_process_add_arg (comm->process, "--force-local");
 	fr_process_add_arg (comm->process, "-v");
 	fr_process_add_arg (comm->process, "-xf");
