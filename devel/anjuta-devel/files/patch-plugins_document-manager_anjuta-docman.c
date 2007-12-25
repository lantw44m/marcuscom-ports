--- plugins/document-manager/anjuta-docman.c.orig	2007-10-09 10:19:41.000000000 +0200
+++ plugins/document-manager/anjuta-docman.c	2007-11-02 12:04:00.000000000 +0100
@@ -919,6 +919,7 @@
 	const gchar *linenum;
 	glong lineno;
 	gboolean is_local_uri;
+	gchar normalized_path_buf[PATH_MAX];
 	gchar *normalized_path = NULL;
 	
 	IAnjutaDocument *doc;
@@ -944,9 +945,11 @@
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
@@ -960,6 +963,7 @@
 		AnjutaDocmanPage *page;
 		gboolean te_is_local_uri;
 		gchar *te_uri;
+		char te_normalized_path_buf[PATH_MAX];
 		gchar *te_normalized_path = NULL;
 		
 		page = (AnjutaDocmanPage *) node->data;
@@ -977,9 +981,11 @@
 		te_is_local_uri = gnome_vfs_uri_is_local (vfs_uri);
 		if (te_is_local_uri)
 			te_normalized_path = realpath (gnome_vfs_uri_get_path (vfs_uri),
-										   NULL);
-		if (te_normalized_path == NULL)
-			te_normalized_path = g_strdup (te_uri);
+										   te_normalized_path_buf);
+		if (te_normalized_path == NULL) {
+			(void) strlcpy (te_normalized_path_buf, te_uri, PATH_MAX);
+			te_normalized_path = te_normalized_path_buf;
+		}
 		gnome_vfs_uri_unref (vfs_uri);
 		
 		if (strcmp (normalized_path, te_normalized_path) == 0
@@ -1001,15 +1007,12 @@
 			an_file_history_push (te_uri, lineno);
 			g_free (uri);
 			g_free (te_uri);
-			g_free (normalized_path);
-			g_free (te_normalized_path);
 			if (IANJUTA_IS_EDITOR(doc))
 				return IANJUTA_EDITOR(doc);
 			else
 				return NULL;
 		}
 		g_free (te_uri);
-		g_free (te_normalized_path);
 		node = g_list_next (node);
 	}
 	te = anjuta_docman_add_editor (docman, uri, NULL);
@@ -1028,7 +1031,6 @@
 		}
 	}
 	g_free (uri);
-	g_free (normalized_path);
 	return te ;
 }
 
