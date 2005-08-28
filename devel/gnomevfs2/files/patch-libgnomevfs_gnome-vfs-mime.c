--- libgnomevfs/gnome-vfs-mime.c.orig	Sun Aug 28 02:00:22 2005
+++ libgnomevfs/gnome-vfs-mime.c	Sun Aug 28 02:07:11 2005
@@ -211,7 +211,7 @@ _gnome_vfs_get_mime_type_internal (Gnome
 
 	if (buffer != NULL) {
 		result = _gnome_vfs_read_mime_from_buffer (buffer);
-		
+
 		if (result != NULL && result != XDG_MIME_TYPE_UNKNOWN) {
 				
 			if ((strcmp (result, "application/x-ole-storage") == 0) ||
@@ -229,9 +229,13 @@ _gnome_vfs_get_mime_type_internal (Gnome
 					result = fn_result;
 				}
 				
-			} else if (fn_result && fn_result != XDG_MIME_TYPE_UNKNOWN &&
+			} else {
+				G_LOCK (mime_mutex);
+				if (fn_result && fn_result != XDG_MIME_TYPE_UNKNOWN &&
 				   xdg_mime_mime_type_subclass (fn_result, result)) {
-				result = fn_result;
+					result = fn_result;
+				}
+				G_UNLOCK (mime_mutex);
 			}
 			
 			return result;
@@ -243,18 +247,27 @@ _gnome_vfs_get_mime_type_internal (Gnome
 				 * accurate source of type information BUT _only_ if
 				 * the extension is a subtype of text/plain.
 				 */
+				G_LOCK (mime_mutex);
 				if ((fn_result != NULL) && (fn_result != XDG_MIME_TYPE_UNKNOWN) &&
 				    xdg_mime_mime_type_subclass (fn_result, "text/plain")) {
+					G_UNLOCK (mime_mutex);
 					return fn_result;
 				}
 
 				/* Didn't find an extension match, assume plain text. */
+				G_UNLOCK (mime_mutex);
 				return "text/plain";
 
-			} else if (_gnome_vfs_sniff_buffer_looks_like_mp3 (buffer)) {
-				return "audio/mpeg";
+			} else {
+				G_LOCK (mime_mutex);
+				if (_gnome_vfs_sniff_buffer_looks_like_mp3 (buffer)) {
+					G_UNLOCK (mime_mutex);
+					return "audio/mpeg";
+				}
+				G_UNLOCK (mime_mutex);
 			}
 		}
+
 	}
 
 	if (use_suffix &&
