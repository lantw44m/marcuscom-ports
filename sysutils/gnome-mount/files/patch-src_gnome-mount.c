--- src/gnome-mount.c.orig	Sun Jun  4 13:20:44 2006
+++ src/gnome-mount.c	Sun Jun  4 13:27:18 2006
@@ -338,6 +338,7 @@ main (int argc, char *argv[])
 
 			fsoptions = NULL;
 
+#ifdef __linux__
 			snprintf (uidbuf, sizeof(uidbuf) - 1, "uid=%d", getuid());
 
 			/* TODO: read defaults from gconf */
@@ -349,6 +350,7 @@ main (int argc, char *argv[])
 			} else if (strcmp (fstype, "udf") == 0) {
 				fsoptions = g_list_append (fsoptions, uidbuf);
 			}
+#endif
 
 			/* TODO: read per-volume settings from gconf and adjust fsoptions */
 
