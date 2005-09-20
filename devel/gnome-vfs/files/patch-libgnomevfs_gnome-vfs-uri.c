--- libgnomevfs/gnome-vfs-uri.c.orig	Tue Sep 20 01:42:29 2005
+++ libgnomevfs/gnome-vfs-uri.c	Tue Sep 20 01:48:49 2005
@@ -844,6 +844,12 @@ make_full_uri_from_relative (const char 
 				char *tmp = separator - 1;
 				if ((separator != mutable_base_uri) && (*tmp != '/')) {
 					*separator = '\0';
+				} else {
+					/* Maybe there is no domain part and this is a toplevel URI's child */
+					char *tmp2 = strstr (mutable_base_uri, ":///");
+					if (tmp2 != NULL && tmp2 + 3 == separator) {
+						*(separator + 1) = '\0';
+					}
 				}
 			}
 		}
