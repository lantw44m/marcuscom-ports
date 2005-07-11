--- logview/logview.c.orig	Mon Jul 11 17:31:04 2005
+++ logview/logview.c	Mon Jul 11 17:31:50 2005
@@ -815,6 +815,7 @@ FileSelectResponse (GtkWidget * chooser,
 {
    char *f;
    LogviewWindow *logview = data;
+   Log *tl;
 
    gtk_widget_hide (GTK_WIDGET (chooser));
    if (response != GTK_RESPONSE_OK)
@@ -834,7 +835,6 @@ FileSelectResponse (GtkWidget * chooser,
 		   }
 	   }
 
-	   Log *tl;
 	   if ((tl = OpenLogFile (f, TRUE)) != NULL)
 	     logview_add_log (logview, tl);
    }
@@ -930,7 +930,7 @@ open_databases (void)
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-regexp.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->regexp_db_path);
@@ -952,7 +952,7 @@ open_databases (void)
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-descript.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->descript_db_path);
@@ -983,7 +983,7 @@ open_databases (void)
 
 	if ( ! found) {
 		g_snprintf (full_name, sizeof (full_name),
-			    "%s/share/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
+			    "%s/gnome-system-log/gnome-system-log-actions.db", LOGVIEWINSTALLPREFIX);
 		if (access (full_name, R_OK) == 0) {
 			found = TRUE;
 			g_free (cfg->action_db_path);
