--- grecord/src/gsr-window.c.orig	Sat Dec 25 20:01:19 2004
+++ grecord/src/gsr-window.c	Sat Dec 25 20:12:13 2004
@@ -29,7 +29,7 @@
 #include <unistd.h>
 
 #include <gnome.h>
-#include <libgnomevfs/gnome-vfs-utils.h>
+#include <libgnomevfs/gnome-vfs.h>
 #include <gconf/gconf-client.h>
 #include <gst/gst.h>
 #include <gst/gconf/gconf.h>
@@ -476,39 +476,53 @@
 {
 	GSRWindowPrivate *priv;
         GMAudioProfile *profile;
-	char *tmp, *command;
-	GError *error;
-	int status;
-	
-	status = 0;
+	char *tmp, *src;
+	GnomeVFSURI *src_uri, *dst_uri;
 
 	priv = window->priv;
-	
+
         profile = gm_audio_profile_choose_get_active (priv->profile);
 
-	tmp = g_strdup_printf ("%s.%s", name,
+	tmp = g_strdup_printf ("file://%s.%s", name,
 			       gm_audio_profile_get_extension (profile));
-	
-	command = g_strdup_printf ("/bin/cp %s %s", priv->record_filename, tmp);
-
-	if (!g_spawn_command_line_sync (command,  NULL, NULL, &status, &error)) {
-		gchar *error_message;
+	src = g_strdup_printf ("file://%s", priv->record_filename);
+	src_uri = gnome_vfs_uri_new (src);
+	dst_uri = gnome_vfs_uri_new (tmp);
+	g_free (src);
+	g_free (tmp);
+	if (src_uri && dst_uri) {
+		GnomeVFSResult result;
+		result = gnome_vfs_xfer_uri (src_uri, dst_uri,
+			GNOME_VFS_XFER_DEFAULT,
+			GNOME_VFS_XFER_ERROR_MODE_ABORT,
+			GNOME_VFS_XFER_OVERWRITE_MODE_REPLACE,
+			NULL, NULL);
+		if (result == GNOME_VFS_OK) {
+			char *title, *short_name;
+			priv->filename = g_strdup_printf ("%s.%s",
+				name, gm_audio_profile_get_extension (profile));
+			short_name = g_path_get_basename (priv->filename);
+			title = g_strdup_printf ("%s - Sound Recorder",
+				short_name);
+			gtk_window_set_title (GTK_WINDOW (window), title);
+			priv->dirty = FALSE;
+			g_free (title);
+		} else {
+			gchar *error_message;
 
-		error_message = g_strdup_printf (_("Could not save the file \" %s\""), error->message);
-		show_error_dialog (GTK_WINDOW (window), error_message);
-		g_free (error_message);
-	}
-	
-	if (status) {
+			error_message = g_strdup_printf (_("Could not save the file \" %s\""), gnome_vfs_result_to_string (result));
+			show_error_dialog (GTK_WINDOW (window), error_message);
+			g_free (error_message);
+		}
+		gnome_vfs_uri_unref (src_uri);
+		gnome_vfs_uri_unref (dst_uri);
+	} else {
 		gchar *error_message;
 
-		error_message = g_strdup_printf (_("Could not save the file \" %s\""), tmp);
+		error_message = g_strdup_printf (_("Could not save the file \" %s.%s\""), name, gm_audio_profile_get_extension (profile));
 		show_error_dialog (GTK_WINDOW (window), error_message);
 		g_free (error_message);
 	}
-
-	g_free (tmp);		
-	g_free (command);		
 }
 
 static void
