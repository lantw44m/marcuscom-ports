--- aisleriot/sol.c.orig	Sun Apr 25 03:03:33 2004
+++ aisleriot/sol.c	Mon May 31 17:25:15 2004
@@ -90,6 +90,16 @@
 #define DEFAULT_VARIATION "klondike.scm"
 #define GNOME_SESSION_BUG
 
+gchar* game_file_to_variation (const gchar* file);
+gchar* game_file_to_variation (const gchar* file)
+{
+  char* p, *buf = g_path_get_basename(file);
+
+  if ((p = strrchr (buf, '.'))) *p = '\0';
+  
+  return buf;
+}  
+
 gchar* game_file_to_name (const gchar* file)
 {
   char* p, *buf = g_path_get_basename(file);
@@ -472,7 +482,7 @@
   dir = gnome_program_locate_file (NULL, GNOME_FILE_DOMAIN_APP_DATADIR,
 	                                        GAMESDIR, FALSE, NULL);
 
-  records = scandir (dir, &game_dents, is_game, alphasort);
+  records = scandir (dir, &game_dents, (gpointer)is_game, alphasort);
   g_free(dir);
 
   if (records >= 0)
@@ -481,14 +491,14 @@
 	  n_games = 0;
 
   for (i = 0; i < n_games; i++) {
-    gchar *game_name = game_file_to_name (game_dents[i]->d_name);
-    if (!strcasecmp (variation, game_name)) {
+    gchar *game_variation = game_file_to_variation (game_dents[i]->d_name);
+    if (!strcasecmp (variation, game_variation)) {
       dont_save = TRUE;
       start_game = g_strdup ((gchar*) game_dents[i]->d_name);
-      g_free (game_name);
+      g_free (game_variation);
       break;
     }
-    g_free (game_name);
+    g_free (game_variation);
   }
   
   gh_enter(argc, argv, main_prog);
