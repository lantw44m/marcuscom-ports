--- plugins/document-manager/anjuta-docman.c.orig	2008-01-10 22:41:20.000000000 +0100
+++ plugins/document-manager/anjuta-docman.c	2008-01-13 17:22:34.000000000 +0100
@@ -1101,6 +1101,7 @@ anjuta_docman_goto_file_line_mark (Anjut
 	const gchar *linenum;
 	gint lineno;
 	gboolean is_local_uri;
+	gchar normalized_path_buf[PATH_MAX];
 	gchar *normalized_path = NULL;
 	
 	IAnjutaDocument *doc;
@@ -1126,9 +1127,11 @@ anjuta_docman_goto_file_line_mark (Anjut
 	/* Get the normalized file path for comparision */
 	is_local_uri = gnome_vfs_uri_is_local (vfs_uri);
 	if (is_local_uri)
-		normalized_path = realpath (gnome_vfs_uri_get_path (vfs_uri), NULL);
-	if (normalized_path == NULL)
-		normalized_path = g_strdup (uri);
+		normalized_path = realpath (gnome_vfs_uri_get_path (vfs_uri), normalized_path_buf);
+	if (normalized_path == NULL) {
+		(void) strlcpy (normalized_path_buf, uri, PATH_MAX);
+		normalized_path = normalized_path_buf;
+	}
 	
 	gnome_vfs_uri_unref (vfs_uri);
 	/* g_free(filename); */
@@ -1150,6 +1153,7 @@ anjuta_docman_goto_file_line_mark (Anjut
 		if (te_uri)
 		{
 			gboolean te_is_local_uri;
+			char te_normalized_path_buf[PATH_MAX];
 			gchar *te_normalized_path;
 		
 			/* Get the normalized file path for comparision */
@@ -1157,9 +1161,13 @@ anjuta_docman_goto_file_line_mark (Anjut
 			te_is_local_uri = gnome_vfs_uri_is_local (vfs_uri);
 			if (te_is_local_uri)
 				te_normalized_path = realpath (gnome_vfs_uri_get_path (vfs_uri),
-											   NULL);
+											   te_normalized_path_buf);
 			else
 				te_normalized_path = g_strdup (te_uri);
+			if (te_normalized_path == NULL) {
+				(void) strlcpy (te_normalized_path_buf, te_uri, PATH_MAX);
+				te_normalized_path = te_normalized_path_buf;
+			}
 			gnome_vfs_uri_unref (vfs_uri);
 
 			if (normalized_path && te_normalized_path)
@@ -1181,9 +1189,7 @@ anjuta_docman_goto_file_line_mark (Anjut
 					anjuta_docman_present_notebook_page (docman, doc);
 					an_file_history_push (te_uri, lineno);
 					g_free (te_uri);
-					g_free (te_normalized_path);
 					g_free (uri);
-					g_free (normalized_path);
 					return IANJUTA_EDITOR (doc);
 				}
 			}
@@ -1192,7 +1198,6 @@ anjuta_docman_goto_file_line_mark (Anjut
 				DEBUG_PRINT ("Unexpected NULL path");
 			}
 			g_free (te_uri);
-			g_free (te_normalized_path);
 		}
 	}
 	/* no deal, open a new document */
@@ -1213,7 +1218,6 @@ anjuta_docman_goto_file_line_mark (Anjut
 		}
 	}
 	g_free (uri);
-	g_free (normalized_path);
 	return te ;
 }
 
