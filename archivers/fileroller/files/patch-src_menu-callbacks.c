--- src/menu-callbacks.c.orig	Sat Jan 31 13:54:09 2004
+++ src/menu-callbacks.c	Sat Jan 31 13:54:23 2004
@@ -661,7 +661,7 @@
 				  int           response,
 				  CopyMoveData *data)
 {
-	FRWindow    *window = data->window;;
+	FRWindow    *window = data->window;
 	char        *folder;
 	char        *new_path;
 
